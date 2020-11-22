#ifndef TEST_BLOOMTESTER_HPP
#define TEST_BLOOMTESTER_HPP

#include <vector>
#include <string>
#include <bloom/bloom.h>

#include "Tester.hpp"
#include "test.hpp"

class BloomTester : public Tester {
private:
    BloomFilter set;
public:
    BloomTester(uint32_t elements): set(elements){
    }

    void insert_words(std::vector<std::string> insert_vec) {
        for (std::string &it: insert_vec) {
            set.insert(it.c_str());
        }
    }
    void check_words(std::vector<std::string> check_vec) {
        for (std::string &it: check_vec) {
            set.find(it.c_str());
        }
    }
};

Tester *create_BloomTester(uint32_t elements) {
    return new BloomTester(elements);
}

#endif
