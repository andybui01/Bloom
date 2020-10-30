/**
 * MIT License
 *
 * Copyright (c) 2020 Andy Bui
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

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
    return -(elements * log(fp_rate)) / pow(log(2), 2);
}
double BloomFilter::calculateNumHash(uint32_t elements, uint32_t size) {
    return size * log(2) / elements;
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
