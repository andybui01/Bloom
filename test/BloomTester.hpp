#ifndef TEST_BLOOMTESTER_HPP
#define TEST_BLOOMTESTER_HPP

#include <vector>
#include <string>
#include <bloom.hpp>

#include "Tester.hpp"

class BloomTester : public Tester {
private:
    BloomFilter bf;
public:
    BloomTester(uint32_t elements): bf(elements){
    }

    void insert_words(std::vector<std::string> insert_vec) {
        for (std::string &it: insert_vec) {
            // cout << it;
            bf.insert(it.c_str());
        }
    }
    void check_words(std::vector<std::string> check_vec) {
        for (std::string &it: check_vec) {
            // cout << it;
            bf.check(it.c_str());
        }
    }
};

Tester *create_BloomTester(uint32_t elements) {
    return new BloomTester(elements);
}

#endif