// Kipras Vytautas Spirgys 1k 1.2gr
// camelCase, klasės pavadinimai iš didžiosios raidės, kintamųjų ir funkcijų iš mažosios

// Linked List is a primitive data type that I have implemented in C++.
// Capacity can be changed at any given point.

// There is also another class, Exception, to handle errors.

// Makefile commands:
// make - Builds everything
// make build - Builds the main executable
// make run - Runs the main executable
// make build_run - Builds and runs the main executable
// make test_build - Builds the test executable
// make test_run - Runs the test executable
// make test_build_run - Builds and runs the test executable
// make clean - Cleans all generated files

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <memory>
#include <iostream>

#define LINKED_LIST_MAX_COUNT 50
#define LINKED_LIST_MAX_ELEMENT_COUNT 10

static int linked_list_count = 0;
static int error = 0;

namespace ip2 {
    class LinkedList {
    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
            Node(int val) : data(val), next(nullptr), prev(nullptr) {}
        };

        struct LinkedListImpl {
            Node* head;
            Node* tail;
            int size;
        };

        void test_for_exceptions(const bool (&arr)[3]);
        LinkedListImpl* impl;

    public:
        LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        ~LinkedList();

        void push_front(int value);
        void push_back(int value);
        int pop_front();
        int pop_back();
        int top();
        int bottom();
        void print_linked_list();

        LinkedList operator+(const LinkedList& other);
        LinkedList operator-(const LinkedList& other);
        LinkedList operator*(const LinkedList& other);
        LinkedList operator/(const LinkedList& other);

        LinkedList& operator+=(const LinkedList& other);
        LinkedList& operator-=(const LinkedList& other);
        LinkedList& operator*=(const LinkedList& other);
        LinkedList& operator/=(const LinkedList& other);

        template <typename Op>
        LinkedList arithmetic_operation(const LinkedList& other, Op op) const;

        void operator+(int value);
        int operator++();
        void operator-(int value);
        int operator--();

        LinkedList operator&(const LinkedList& other);
        LinkedList& operator&=(const LinkedList& other);

        bool equals(const LinkedList& other);
        bool operator==(const LinkedList& other) const;
        bool operator!=(const LinkedList& other) const;
        bool operator>(const LinkedList& other) const;
        bool operator<(const LinkedList& other) const;
        bool operator>=(const LinkedList& other) const;
        bool operator<=(const LinkedList& other) const;

        void operator!() const;
        bool operator[](int value) const;
    };

    class LinkedListException : public std::exception {
    public:
        explicit LinkedListException(const std::string& message) : msg(message) {}
        const char* what() const noexcept override {
            error = 1;
            return msg.c_str();
        }
    private:
        std::string msg;
    };

    class ExceededElementCountException : public LinkedListException {
    public:
        ExceededElementCountException() : LinkedListException("Error 1: Exceeded " + std::to_string(LINKED_LIST_MAX_ELEMENT_COUNT) + " element count\n") {}
    };

    class EmptyLinkedListException : public LinkedListException {
    public:
        EmptyLinkedListException() : LinkedListException("Error 2: Linked list is empty\n") {}
    };

    class ExceededLinkedListCountException : public LinkedListException {
    public:
        ExceededLinkedListCountException() : LinkedListException("Error 3: Exceeded " + std::to_string(LINKED_LIST_MAX_COUNT) + " linked list count\n") {}
    };

    class UninitializedLinkedListException : public LinkedListException {
    public:
        UninitializedLinkedListException() : LinkedListException("Error 4: Linked list is not initialized\n") {}
    };

    class MismatchedLinkedListSizesException : public LinkedListException {
    public:
        MismatchedLinkedListSizesException() : LinkedListException("Error 5: Linked list sizes do not match\n") {}
    };
}

#endif
