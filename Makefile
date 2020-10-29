CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -I.
TARGET = main

.PHONY: all clean

all: driver.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) driver.o

driver.o: driver.cpp bloom.hpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

clean:
	rm -f $(TARGET)
	rm *.o
