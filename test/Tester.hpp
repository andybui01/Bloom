#ifndef TEST_TESTER_HPP
#define TEST_TESTER_HPP

#include <vector>
#include <string>

class Tester {
public:
    virtual void insert_words(std::vector<std::string> insert_vec) = 0;
    virtual void check_words(std::vector<std::string> check_vec) = 0;
};

#endif