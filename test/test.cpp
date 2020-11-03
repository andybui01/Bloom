#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bloom.hpp>
#include <chrono>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Test {

private:
    vector<string> insert_vec;
    vector<string> check_vec;


public:
    Test() {
        string line;
        ifstream file("test/list.txt");
        
        while(getline(file, line)) {
            insert_vec.push_back(line);
        }
        file.close();

        ifstream file2("test/check_list.txt");
        
        while(getline(file2, line)) {
            check_vec.push_back(line);
        }
        file2.close();
    }

    void run() {
        printf("Bloom\n");
        BloomFilter bf(100000);
        auto t1 = high_resolution_clock::now();

        // insert
        for (string &it: insert_vec) {
            // cout << it;
            bf.insert(it.c_str());
        }

        // check
        // for (string &it: check_vec) {
        //     // cout << it;
        //     bf.check(it.c_str());
        // }

        auto t2 = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << duration << endl;
    }

    void run2() {
        printf("unordered_set\n");
        unordered_set<string> set;
        auto t1 = high_resolution_clock::now();

        // insert
        for (string &it: insert_vec) {
            set.insert(it.c_str());
        }

        // check
        for (string &it: check_vec) {
            set.find(it.c_str());
        }

        auto t2 = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << duration << endl;
    }
};

int main() {
    Test test;
    test.run();
    test.run2();
    // test.run();

    return 0;
}
