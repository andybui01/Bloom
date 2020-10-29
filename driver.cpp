#include <iostream>
#include <bloom.hpp>

using namespace std;
int main() {
    BloomFilter bf(50000);

    cout << bf.getSize() << " " << bf.getNumHash() << endl;
}
