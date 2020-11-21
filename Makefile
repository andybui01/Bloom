CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -std=c++11
TARGET = main
TEST_TARGET = runtest

.PHONY: test list clean

test: test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test/test.o

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
