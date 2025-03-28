CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = myTest.cpp demo.cpp test.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = demo
testEXEC = test

all: build

build: $(EXEC)

$(EXEC): myTest.o demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test_build: $(testEXEC)

$(testEXEC): myTest.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

run: build
	./$(EXEC)

test_run: test_build
	./$(testEXEC)


build_run: build run

test_build_run: test_build test_run

%.o: %.cpp myTest.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean
clean:
	rm -f $(OBJ) $(EXEC) $(testEXEC)
