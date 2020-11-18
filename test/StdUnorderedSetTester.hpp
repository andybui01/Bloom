#ifndef TEST_STDUNORDEREDSETTESTER_HPP
#define TEST_STDUNORDEREDSETTESTER_HPP

#include <vector>
#include <string>
#include <unordered_set>

#include "Tester.hpp"

class StdUnorderedSetTester : public Tester {
private:
    std::unordered_set<std::string> set;
public:

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

Tester *create_StdUnorderedSetTester() {
    return new StdUnorderedSetTester;
}

#endif