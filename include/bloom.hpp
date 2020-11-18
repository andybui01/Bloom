#ifndef BLOOM_HPP
#define BLOOM_HPP

#define ROUND_UP(x, y) ((((x) + (y) - 1) / (y)) * (y))
#define CEILING(x, y) (((x) + (y) - 1) / (y))

#include <math.h>
#include <iostream>
#include <stdint.h>

class BloomFilter {

private:

    // Size of bitmap
    uint32_t size;

    // Number of hash functions used
    int num_hash;

    // False-positive rate
    double fp_rate;

    // Bitmap
    uint32_t* bitmap;

    uint32_t calculateSize(uint32_t elements, double fp_rate);
    int calculateNumHash(uint32_t elements, uint32_t size);
    inline void bitmap_set(uint32_t bit_index);
    inline uint32_t bitmap_check(uint32_t bit_index);


public:
    BloomFilter(uint32_t elements);
    BloomFilter(uint32_t elements, double fp_rate);
    void insert(const char* str);
    int check(const char* str);

};

#endif
