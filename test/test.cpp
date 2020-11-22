#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// benchmarking
#include <chrono>
#include <sys/resource.h>
#include <unistd.h>

// random
// #include <locale.h>

// testers
#include "test.hpp"
#include "Tester.hpp"
#include "BloomTester.hpp"
#include "StdUnorderedSetTester.hpp"
#include "DenseHashTester.hpp"
#include "SparseHashTester.hpp"
#include "RobinSetTester.hpp"

using namespace std;
using namespace std::chrono;

typedef void (*insert_f)(const char*);
typedef int (*check_f)(const char*);


struct HashTableTester {
    const char* name;
    Tester *tester;
};

long get_mem_usage() {
    struct rusage *data = (struct rusage *) malloc(sizeof(struct rusage));
    getrusage(0, data);
    return data->ru_maxrss;
}

int main(int argc, char **argv) {

    (void) argc;

    // read words into vectors
    vector<string> insert_vec = read_insert_list();
    vector<string> check_vec = read_check_list();

    int num_elements = stoi(argv[1]);

    HashTableTester hash_tables[] = {
        {"Bloom filter", create_BloomTester(num_elements)},
        {"std unordered set", create_StdUnorderedSetTester()},
        {"google dense hash set", create_DenseHashTester()},
        {"google sparse hash set", create_SparseHashTester()},
        {"TSL robin set", create_RobinSetTester()}
    };

    int num = sizeof(hash_tables)/sizeof(struct HashTableTester);

    printf("%-10d", num_elements);

    for (int i = 0; i < num; ++i) {
        HashTableTester table = hash_tables[i];

        // cout << table.name << endl;

        auto m1 = get_mem_usage();
        auto t1 = high_resolution_clock::now();

        table.tester->insert_words(insert_vec);

        auto m2 = get_mem_usage();
        auto t2 = high_resolution_clock::now();

        auto mem = m2 - m1;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();


        printf("%-5lld", duration/1000);
        // sleep(10);


        t1 = high_resolution_clock::now();
        table.tester->check_words(check_vec);

        t2 = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        // printf("find time: %lld\n", duration);
        // printf("mem: %ld\n", mem);

    }

    printf("\n");

    return 0;
}

vector<string> read_insert_list() {

    vector<string> insert_vec;

    string line;
    ifstream file("test/list.txt");

    while(getline(file, line)) {
        insert_vec.push_back(line);
    }
    file.close();

    return insert_vec;
}
vector<string> read_check_list() {

    vector<string> check_vec;

    string line;
    ifstream file2("test/check_list.txt");

    while(getline(file2, line)) {
        check_vec.push_back(line);
    }
    file2.close();

    return check_vec;
}
