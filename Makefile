CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -pthread
TARGET = main
TEST_TARGET = runtest

.PHONY: bloom test list clean

bloom: driver.o bloom.o murmur.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) driver.o bloom.o murmur.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

bloom.o: bloom.cpp include/bloom.hpp
	$(CXX) $(CXXFLAGS) -c bloom.cpp

murmur.o: MurmurHash2.cpp include/MurmurHash2.h
	$(CXX) $(CXXFLAGS) -o murmur.o -c MurmurHash2.cpp

test: bloom.o test.o murmur.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test/test.o bloom.o murmur.o

test.o: test/test.cpp $(wildcard test/*.hpp)
	$(CXX) $(CXXFLAGS) -c -o test/test.o test/test.cpp

list:
	python3 scripts/words_gen.py > test/list.txt
	python3 scripts/words_gen.py > test/check_list.txt

clean:
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)
	rm *.o
	rm **/*.o
