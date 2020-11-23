#ifndef TEST_ROBINSETTESTER_HPP
#define TEST_ROBINSETTESTER_HPP

#include <vector>
#include <string>
#include <tsl/robin_set.h>

#include "Tester.hpp"


class RobinSetTester: public Tester {
private:
    tsl::robin_set<std::string> set;
public:
    void insert_words(std::vector<std::string> insert_vec) {
        for (std::string &it: insert_vec) {
            // cout << it;
            set.insert(it);
        }
    }
    void check_words(std::vector<std::string> check_vec) {
        for (std::string &it: check_vec) {
            // cout << it;
            set.find(it);
        }
    }
};

Tester *create_RobinSetTester() {
    return new RobinSetTester;
}

#endif