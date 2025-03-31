CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

SRCS = LinkedList.cpp Test.cpp Demo.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

TEST_BIN = Test.exe
DEMO_BIN = Demo.exe

TEST_LOG = test.txt
DEMO_LOG = demo.txt

all: $(TEST_BIN) $(DEMO_BIN)

%.o: %.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_BIN): LinkedList.o Test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DEMO_BIN): LinkedList.o Demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TEST_BIN)
	$(TEST_BIN) > $(TEST_LOG) 2>&1

demo: $(DEMO_BIN)
	$(DEMO_BIN) > $(DEMO_LOG) 2>&1

run: test demo

clean:
	del /F /Q *.o $(TEST_BIN) $(DEMO_BIN) $(TEST_LOG) $(DEMO_LOG) 2>nul || rm -f *.o $(TEST_BIN) $(DEMO_BIN) $(TEST_LOG) $(DEMO_LOG)

.PHONY: all test demo run clean
