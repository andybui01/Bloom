# Bloom
🌸 C++ implementation of a Bloom filter

Header-only implementation of a Bloom filter in C++. Header files can be found under `include/bloom/`.
Tests have been conducted using Yann Collet's `xxhash`, and the header file for `xxhash` can be found under the bloom include directory as well. All tests conducted with at least `-O1` flag on gcc.

Actual benchmarking can be found here: https://andybui01.github.io/bloom-filter/#implementation-and-benchmarks

### Running
```
// run tests
make list
make test
make run

// clean
make clean
```
