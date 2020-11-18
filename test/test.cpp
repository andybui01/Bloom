#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "test.hpp"
#include "Tester.hpp"
#include "BloomTester.hpp"
#include "StdUnorderedSetTester.hpp"

using namespace std;
using namespace std::chrono;

typedef void (*insert_f)(const char*);
typedef int (*check_f)(const char*);


struct HashTableTester {
    const char* name;
    Tester *tester;
};



int main() {

    // read words into vectors
    vector<string> insert_vec = read_insert_list();
    vector<string> check_vec = read_check_list();

    HashTableTester hash_tables[] = {
        {"Bloom filter", create_BloomTester(100000)},
        {"std unordered set", create_StdUnorderedSetTester()}
    };

    int num = sizeof(hash_tables)/sizeof(struct HashTableTester);

    for (int i = 0; i < num; ++i) {
        HashTableTester table = hash_tables[i];

        cout << table.name << endl;

        auto t1 = high_resolution_clock::now();
        table.tester->insert_words(insert_vec);

        auto t2 = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        cout << duration << endl;

        t1 = high_resolution_clock::now();
        table.tester->insert_words(check_vec);

        t2 = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        cout << duration << endl;
    }

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

