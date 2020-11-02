#include <iostream>
#include <bloom.hpp>

using namespace std;
int main() {
    int a = 100;

    BloomFilter bf(a);
    printf("size: %d num_hash: %d\n", bf.getSize(), bf.getNumHash());
    printf("found: %d\n", bf.check("andy"));
    bf.insert("andy");
    printf("found: %d\n", bf.check("andy"));
}
