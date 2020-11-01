#include <bloom.hpp>
#include <stdlib.h>
#include <string.h>

/**
 * Public
 **/

// Constructor method, use default false-positve rate of 1%
BloomFilter::BloomFilter(uint32_t elements): elements(elements), fp_rate(0.01) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
}

// Constructor method with specified false-positive rate
BloomFilter::BloomFilter(uint32_t elements, double fp_rate): elements(elements), fp_rate(fp_rate) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
}

// void BloomFilter::insert(char* str) {
//     for (int i = 0; i < num_hash; ++i) {
//         uint64_t bit_index = hash(str, salts[i]) % (size * 32);
//     }
// }

double BloomFilter::getSize() {
    return size;
}

int BloomFilter::getNumHash() {
    return num_hash;
}

/**
 * Private
 **/

uint32_t BloomFilter::calculateSize(uint32_t elements, double fp_rate) {
    return ROUND_UP(-(elements * log(fp_rate)) / pow(log(2), 2), 32);
}

int BloomFilter::calculateNumHash(uint32_t elements, uint32_t size) {
    return CEILING(size * log(2), elements);
}

// Hash function that implements Dan Bernstein's djb2:
// http://www.cse.yorku.ca/~oz/hash.html
uint64_t BloomFilter::hash(char* str, const char* salt) {
    uint64_t hash = 5381;
    int c;

    // salt the string
    char* salted = (char*) malloc(1 + strlen(str) + strlen(salt));
    strcpy(salted, str);
    strcat(salted, salt);

    std::cout << salted << std::endl;

    char* temp = salted;

    while ((c = *salted++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    free(temp); // does nothing?
    return hash;
}
