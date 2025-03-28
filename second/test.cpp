#include <cassert>
#include <fstream>
#include <ios>
#include <iostream>
#include "myTest.hpp"

using namespace ip2;

void checkDuplication() {
    LinkedList alpha;
    alpha.push_front(10);
    LinkedList beta = alpha;
    assert(beta.pop_front() == 10);
}

void verifyAssignment() {
    LinkedList container;
    container.push_back(5);
    LinkedList receiver;
    receiver = container;
    assert(receiver.pop_back() == 5);
}

void evaluateInsertRemove() {
    LinkedList sequence;
    sequence.push_back(20);
    sequence.push_front(10);
    assert(sequence.pop_front() == 10);
    assert(sequence.pop_back() == 20);
}

void validateEdgeElements() {
    LinkedList collection;
    collection.push_front(40);
    collection.push_back(30);
    collection.push_back(35);
    assert(collection.top() == 40);
    assert(collection.bottom() == 35);
}

int executeTests() {
    std::ofstream logFile("test_output.txt");
    if (!logFile) {
        std::cerr << "Error opening test output file\n";
        return EXIT_FAILURE;
    }
    
    auto* originalBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(logFile.rdbuf());

    std::cerr << "\ntesting copy_constructor: ";
    checkDuplication();
    std::cerr << "\ntesting copy_assignment: ";
    verifyAssignment();
    std::cerr << "\ntesting push_pop: ";
    evaluateInsertRemove();
    std::cerr << "\ntesting top_bottom: ";
    validateEdgeElements();

    std::cerr << "\nAll implemented tests passed successfully\n";
    
    std::cerr.rdbuf(originalBuffer);
    logFile.close();
    return EXIT_SUCCESS;
}

int main() {
    return executeTests();
}
