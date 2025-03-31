// Kipras Vytautas Spirgys 1k 1.2gr
// camelCase, klasės pavadinimai iš didžiosios raidės, kintamųjų ir funkcijų iš mažosios

// Linked List is a primitive data type I implemented in C++.
// Capacity can be changed at any given point.

// There is also another class, Exception, that handles errors.

// Makefile commands:
// make - Builds everything
// make build - Builds the main executable
// make run - Runs the main executable
// make build_run - Builds and runs the main executable
// make test_build - Builds the test executable
// make test_run - Runs the test executable
// make test_build_run - Builds and runs the test executable
// make clean - Cleans all generated files

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include <cstddef>
#include <string>
#include <exception>

namespace myNamespace {

    class EmptyListException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Error: Cannot operate on empty list";
        }
    };

    class LinkedList {
    private:
        class Impl; 
        std::unique_ptr<Impl> pImpl;

    public:
        LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        ~LinkedList();

        bool empty() const;
        size_t size() const;
        int front() const;
        int back() const;
        int operator[](int index) const;

        void append(int value);
        void prepend(int value);
        void removeFront();
        void clear();

        LinkedList& operator+=(int value);  
        LinkedList& operator-=(int value);  
        LinkedList& operator<<(int value);  
        LinkedList& operator!();            

        bool operator==(const LinkedList& other) const;
        bool operator!=(const LinkedList& other) const;
        bool operator<(const LinkedList& other) const;
        bool operator<=(const LinkedList& other) const;
        bool operator>(const LinkedList& other) const;
        bool operator>=(const LinkedList& other) const;

        std::string toString() const;
        int find(int value) const;
    };

}

#endif
