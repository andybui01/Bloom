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
    vector<string> vec;


public:
    Test() {
        string line;
        ifstream file("test/list.txt");
        
        while(getline(file, line)) {
            vec.push_back(line);
        }
        file.close();
    }

    void run() {
        BloomFilter bf(100000);
        auto t1 = high_resolution_clock::now();

        for (string &it: vec) {
            // cout << it;
            bf.insert(it.c_str());
        }
        auto t2 = high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << duration << endl;
    }

    void run2() {
        unordered_set<string> set;

        auto t1 = high_resolution_clock::now();

        for (string &it: vec) {
            // cout << it;
            set.insert(it.c_str());
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
    test.run();

    return 0;
}
