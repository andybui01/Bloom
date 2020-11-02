CXX = g++
CXXFLAGS = -Wall -Wextra -I.
TARGET = main
TEST_TARGET = runtest

.PHONY: bloom test list clean

bloom: driver.o bloom.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) driver.o bloom.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

bloom.o: bloom.cpp bloom.hpp
	$(CXX) $(CXXFLAGS) -c bloom.cpp

test: bloom.o test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test/test.o bloom.o

test.o: test/test.cpp
	$(CXX) $(CXXFLAGS) -c -o test/test.o test/test.cpp

list:
	python3 scripts/words_gen.py > test/list.txt

clean:
	rm -f $(TARGET)
	rm *.o
	rm **/*.o
