#ifndef TEST_SPARSEHASHTESTER_HPP
#define TEST_SPARSEHASHTESTER_HPP

#include <vector>
#include <string>
#include <sparsehash/sparse_hash_set>
#include <functional>

#include "Tester.hpp"
using google::sparse_hash_set;

#ifndef EQSTR
#define EQSTR
struct eqstr
{
    bool operator()(const char* s1, const char* s2) const
    {
        return (s1 == s2) || (s1 && s2 && strcmp(s1, s2) == 0);
    }
};
#endif

class SparseHashTester: public Tester {
private:
    sparse_hash_set<const char*, std::hash<const char*>, eqstr> set;
public:
    void insert_words(std::vector<std::string> insert_vec) {
        for (std::string &it: insert_vec) {
            // cout << it;
            set.insert(it.c_str());
        }
    }
    void check_words(std::vector<std::string> check_vec) {
        for (std::string &it: check_vec) {
            // cout << it;
            set.find(it.c_str());
        }
    }
};

Tester *create_SparseHashTester() {
    return new SparseHashTester;
}

#endif