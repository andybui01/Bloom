#include <iostream>
#include <bloom.hpp>
#include <chrono>

using namespace std;
int main() {
    int a = 100;

    BloomFilter bf(a);
    auto t1 = std::chrono::high_resolution_clock::now();
    bf.insert("andy");
    bf.check("andy");
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration;
}
