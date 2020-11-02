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
    bitmap = (uint32_t *) calloc(size / 32, 4);
}

// Constructor method with specified false-positive rate
BloomFilter::BloomFilter(uint32_t elements, double fp_rate): elements(elements), fp_rate(fp_rate) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
    bitmap = (uint32_t *) calloc(size / 32, 4);
}

void BloomFilter::insert(char* str) {
    for (int i = 0; i < num_hash; ++i) {
        uint32_t bit_index = hash(str, salts[i]) % size;
        bitmap_set(bit_index);
    }
}

int BloomFilter::check(char* str) {
    for (int i = 0; i < num_hash; ++i) {
        uint32_t bit_index = hash(str, salts[i]) % size;
        if (!(bitmap_check(bit_index)))
            return 0;
    }
    return 1;
}

uint32_t BloomFilter::getSize() {
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

    char* temp = salted;

    while ((c = *salted++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    free(temp); // does nothing?
    return hash;
}

void BloomFilter::bitmap_set(uint32_t bit_index) {
    uint32_t index = bit_index / 32;
    int offset = bit_index % 32;
    bitmap[index] |= (1 << offset);
}

uint32_t BloomFilter::bitmap_check(uint32_t bit_index) {
    uint32_t index = bit_index / 32;
    int offset = bit_index % 32;
    return (bitmap[index] & (1 << offset));
}
