// LinkedListTest.cpp - Comprehensive test suite for the LinkedList class
// This file contains various test cases to verify the correctness of the LinkedList
// implementation, including basic operations, copy semantics, operator overloads,
// edge cases, and more.

#include "LinkedList.h"
#include <iostream>
#include <cassert>

using namespace myNamespace;

void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void testBasicOperations() {
    LinkedList testList;
    const int FIRST_VALUE = 10;
    const int SECOND_VALUE = 20;
    const int PREPENDED_VALUE = 30;
    
    assert(testList.empty());
    assert(testList.size() == 0);
    printTestResult("Initial empty state", true);
    
    testList.append(FIRST_VALUE);
    assert(!testList.empty());
    assert(testList.size() == 1);
    assert(testList.front() == FIRST_VALUE);
    printTestResult("Append operation", true);
    
    testList.append(SECOND_VALUE);
    assert(testList.size() == 2);
    assert(testList.front() == FIRST_VALUE);
    assert(testList.back() == SECOND_VALUE);
    
    testList.prepend(PREPENDED_VALUE);
    assert(testList.size() == 3);
    assert(testList.front() == PREPENDED_VALUE);
    assert(testList.back() == SECOND_VALUE);
    printTestResult("Prepend operation", true);
    
    testList.removeFront();
    assert(testList.size() == 2);
    assert(testList.front() == FIRST_VALUE);
    
    testList.removeFront();
    assert(testList.size() == 1);
    assert(testList.front() == SECOND_VALUE);
    
    testList.removeFront();
    assert(testList.empty());
    printTestResult("Remove front operations", true);
    
    bool exceptionThrown = false;
    try { testList.front(); } 
    catch (const EmptyListException&) { exceptionThrown = true; }
    assert(exceptionThrown);
    
    exceptionThrown = false;
    try { testList.removeFront(); } 
    catch (const EmptyListException&) { exceptionThrown = true; }
    assert(exceptionThrown);
    
    printTestResult("Exception handling", true);
}

void testCopyConstructor() {
    LinkedList originalList;
    const int VALUES[] = {10, 20, 30};
    for (int value : VALUES) {
        originalList.append(value);
    }
    
    LinkedList copiedList(originalList);
    assert(copiedList.size() == 3);
    assert(copiedList.front() == VALUES[0]);
    
    copiedList.removeFront();
    assert(copiedList.size() == 2);
    assert(copiedList.front() == VALUES[1]);
    assert(originalList.size() == 3);
    assert(originalList.front() == VALUES[0]);
    
    printTestResult("Copy constructor", true);
}

void testClear() {
    LinkedList testList;
    testList.append(10);
    testList.append(20);
    
    testList.clear();
    assert(testList.empty());
    assert(testList.size() == 0);
    
    printTestResult("Clear operation", true);
}

void testOperators() {
    LinkedList testList;
    const int APPENDED_VALUE = 10;
    const int PREPENDED_VALUE = 99;
    
    testList += APPENDED_VALUE;
    assert(testList.size() == 1);
    assert(testList.front() == APPENDED_VALUE);
    
    testList -= APPENDED_VALUE;
    assert(testList.empty());
    
    testList.append(APPENDED_VALUE);
    testList.append(20);
    !testList;
    assert(testList.empty());
    
    testList.append(APPENDED_VALUE);
    testList.append(20);
    testList.append(30);
    
    assert(testList.find(APPENDED_VALUE) == 0);
    assert(testList.find(20) == 1);
    assert(testList.find(30) == 2);
    assert(testList.find(40) == -1);
    
    testList << PREPENDED_VALUE;
    assert(testList.front() == PREPENDED_VALUE);
    
    printTestResult("Operator overloads", true);
}

void testComparisonOperators() {
    LinkedList list1, list2;
    
    assert(list1 == list2);
    assert(!(list1 < list2));
    
    list1.append(10);
    assert(list1 != list2);
    assert(list1 > list2);
    
    list2.append(10);
    assert(list1 == list2);
    
    list1.append(20);
    list2.append(30);
    assert(list1 < list2);
    
    printTestResult("Comparison operators", true);
}

void testMultipleObjects() {
    const int NUM_LISTS = 5;
    LinkedList lists[NUM_LISTS];
    
    for (int i = 0; i < NUM_LISTS; ++i) {
        for (int j = 0; j < 3; ++j) {
            lists[i].append(i * 10 + j);
        }
    }
    
    for (int i = 0; i < NUM_LISTS - 1; ++i) {
        for (int j = 0; j < NUM_LISTS - i - 1; ++j) {
            if (lists[j] > lists[j + 1]) {
                std::swap(lists[j], lists[j + 1]);
            }
        }
    }
    
    for (int i = 1; i < NUM_LISTS; ++i) {
        assert(lists[i-1] <= lists[i]);
    }
    
    printTestResult("Multiple objects", true);
}

void testToString() {
    LinkedList testList;
    
    testList.append(10);
    testList.append(20);
    testList.append(30);
    
    std::string actualOutput = testList.toString();
    std::string expectedOutput = "LinkedList: 10 -> 20 -> 30";
    bool isMatch = (actualOutput == expectedOutput);
    
    printTestResult("ToString output", isMatch);
}

void testEdgeCases() {
    LinkedList testList;
    const int VALUES[] = {10, 20, 30};
    for (int value : VALUES) {
        testList.append(value);
    }
    
    testList.removeFront();
    assert(testList.front() == 20);
    
    testList << 30;
    assert(testList.front() == 30);
    
    testList.clear();
    const int LARGE_SIZE = 1000;
    for (int i = 0; i < LARGE_SIZE; ++i) {
        testList.append(i);
    }
    
    assert(testList.size() == LARGE_SIZE);
    assert(testList.front() == 0);
    
    for (int i = 0; i < LARGE_SIZE; ++i) {
        assert(testList.front() == i);
        testList.removeFront();
    }
    
    assert(testList.empty());
    
    printTestResult("Edge cases", true);
}

int main() {
    try {
        std::cout << "Running LinkedList tests..." << std::endl;
        
        testBasicOperations();
        testCopyConstructor();
        testClear();
        testOperators();
        testComparisonOperators();
        testMultipleObjects();
        testToString();
        testEdgeCases();
        
        std::cout << "All tests completed successfully!" << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception occurred" << std::endl;
    }
    return 0;
}
