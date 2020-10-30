CXX = g++
CXXFLAGS = -Wall -Wextra -I.
TARGET = main

.PHONY: all clean

all: driver.o bloom.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) driver.o bloom.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

bloom.o: bloom.cpp bloom.hpp
	$(CXX) $(CXXFLAGS) -c bloom.cpp

clean:
	rm -f $(TARGET)
	rm *.o
