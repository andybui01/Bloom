#ifndef TEST_DENSEHASHTESTER_HPP
#define TEST_DENSEHASHTESTER_HPP

#include <vector>
#include <string>
#include <sparsehash/dense_hash_set>
#include <functional>

#include "Tester.hpp"
using google::dense_hash_set;

#ifndef EQSTR
#define EQSTR
struct eqstr
{
    bool operator()(std::string s1, std::string s2) const
    {
        return (s1 == s2);
    }
};
#endif

class DenseHashTester: public Tester {
private:
    dense_hash_set<std::string, std::hash<std::string>> set;
public:
    DenseHashTester() {
        set.set_empty_key("");
    }

    void insert_words(std::vector<std::string> insert_vec) {
        for (std::string &it: insert_vec) {
            set.insert(it);
        }
    }
    void check_words(std::vector<std::string> check_vec) {
        for (std::string &it: check_vec) {
            set.find(it);
        }
    }
};

Tester *create_DenseHashTester() {
    return new DenseHashTester;
}

#endif
