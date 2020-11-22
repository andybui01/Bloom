# Bloom
🌸 C++ implementation of a Bloom filter

Header-only implementation of a Bloom filter in C++. Header files can be found under `include/bloom/`.

Benchmarks have been conducted using Yann Collet's `xxhash`, and the header file for `xxhash` can be found under the bloom include directory as well. All tests conducted with at least `-O1` flag on gcc.

### Running
```
// run benchmarks
make list
make test
make run

// clean
make clean
```
