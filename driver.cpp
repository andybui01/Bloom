#include <iostream>
#include <bloom.hpp>

using namespace std;
int main() {
    int a = 100;

    char* andy;
    andy = "andy";
    const char* salt = "salty";

    BloomFilter bf(a);

    cout << bf.getSize() << " " << bf.getNumHash() << endl;
}
