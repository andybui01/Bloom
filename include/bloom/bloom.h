#ifndef BLOOM_H
#define BLOOM_H

#define ROUND_UP(x, y) ((((x) + (y) - 1) / (y)) * (y))
#define CEILING(x, y) (((x) + (y) - 1) / (y))

#include <math.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t MurmurHash2 ( const void * key, int len, uint32_t seed );

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

    uint32_t calculateSize(uint32_t elements, double fp_rate) {

        uint32_t size = -(elements * log(fp_rate)) / pow(log(2), 2);

        // https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
        // Alternate: round to nearest power of 2 and use bit-AND with size - 1 
        // to get modulus
        // size--;
        // size |= size >> 1;
        // size |= size >> 2;
        // size |= size >> 4;
        // size |= size >> 8;
        // size |= size >> 16;
        // size++;

        return ROUND_UP(size, 32);
    }

    int calculateNumHash(uint32_t elements, uint32_t size) {
        return CEILING(size * log(2), elements);
    }

    inline void bitmap_set(uint32_t bit_index) {
        bitmap[bit_index >> 5] |= (1 << (bit_index & 31));
    }

    inline uint32_t bitmap_check(uint32_t bit_index) {
        return (bitmap[bit_index >> 5] & (1 << (bit_index & 31)));
    }



public:

    // Constructor method, use default false-positve rate of 1%
    BloomFilter(uint32_t elements): fp_rate(0.01) {
        size = calculateSize(elements, fp_rate);
        num_hash = calculateNumHash(elements, size);
        bitmap = (uint32_t *) calloc(size / 32, 4);
    }

    // Constructor method with specified false-positive rate
    BloomFilter(uint32_t elements, double fp_rate): fp_rate(fp_rate) {
        size = calculateSize(elements, fp_rate);
        num_hash = calculateNumHash(elements, size);
        bitmap = (uint32_t *) calloc(size / 32, 4);
    }

    void insert(const char* str) {
        for (int i = 0; i < num_hash; ++i) {
            uint32_t bit_index = MurmurHash2(str, strlen(str), i) % size;
            bitmap_set(bit_index);
        }
    }

    int find(const char* str) {
        for (int i = 0; i < num_hash; ++i) {
            uint32_t bit_index = MurmurHash2(str, strlen(str), i) % size;
            if (!(bitmap_check(bit_index)))
                return 0;
        }
        return 1;
    }

};

uint32_t MurmurHash2 ( const void * key, int len, uint32_t seed ) {
    // 'm' and 'r' are mixing constants generated offline.
    // They're not really 'magic', they just happen to work well.

    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    // Initialize the hash to a 'random' value

    uint32_t h = seed ^ len;

    // Mix 4 bytes at a time into the hash

    const unsigned char * data = (const unsigned char *)key;

    while(len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    // Handle the last few bytes of the input array

    switch(len) {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    // Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
} 

#endif
