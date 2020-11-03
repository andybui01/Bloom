#include <bloom.hpp>
#include <stdlib.h>
#include <string.h>
#include <MurmurHash2.h>

/**
 * Public
 **/

// Constructor method, use default false-positve rate of 1%
BloomFilter::BloomFilter(uint32_t elements): fp_rate(0.01) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
    bitmap = (uint32_t *) calloc(size / 32, 4);
}

// Constructor method with specified false-positive rate
BloomFilter::BloomFilter(uint32_t elements, double fp_rate): fp_rate(fp_rate) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
    bitmap = (uint32_t *) calloc(size / 32, 4);
}

void BloomFilter::insert(const char* str) {
    for (int i = 0; i < num_hash; ++i) {
        uint32_t bit_index = MurmurHash2(str, strlen(str), i) % size;
        bitmap_set(bit_index);
    }
}

int BloomFilter::check(const char* str) {
    for (int i = 0; i < num_hash; ++i) {
        uint32_t bit_index = MurmurHash2(str, strlen(str), i) % size;
        if (!(bitmap_check(bit_index)))
            return 0;
    }
    return 1;
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

inline void BloomFilter::bitmap_set(uint32_t bit_index) {
    bitmap[bit_index >> 5] |= (1 << (bit_index & 31));
}

inline uint32_t BloomFilter::bitmap_check(uint32_t bit_index) {
    return (bitmap[bit_index >> 5] & (1 << (bit_index & 31)));
}
