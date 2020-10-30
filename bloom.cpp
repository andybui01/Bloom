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

/**
 * Public
 **/

// Constructor method, use default false-positve rate of 1%
BloomFilter::BloomFilter(int elements): elements(elements), fp_rate(0.01) {
    size = calculateSize(elements, fp_rate);
    num_hash = calculateNumHash(elements, size);
}

// Constructor method with specified false-positive rate
BloomFilter::BloomFilter(int elements, double fp_rate): elements(elements), fp_rate(fp_rate) {
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

int BloomFilter::calculateSize(int elements, double fp_rate) {
    return -(elements * log(fp_rate)) / pow(log(2), 2);
}
double BloomFilter::calculateNumHash(int elements, int size) {
    return size * log(2) / elements;
}
