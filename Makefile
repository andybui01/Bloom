CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -std=c++11 -O3
TARGET = main
TEST_TARGET = runtest

LIST_LENGTH = 5

.PHONY: test list clean run

test: test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test/test.o

test.o: test/test.cpp $(wildcard test/*.hpp)
	$(CXX) $(CXXFLAGS) -c -o test/test.o test/test.cpp

list:
	python3 scripts/words_gen.py $(LIST_LENGTH) > test/list.txt
	python3 scripts/words_gen.py $(LIST_LENGTH) > test/check_list.txt

run:
	./$(TEST_TARGET) $(LIST_LENGTH)

clean:
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)
	rm **/*.o
