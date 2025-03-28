#include "myTest.hpp"

namespace ip2 {
    LinkedList::LinkedList() : impl(new LinkedListImpl()) {
        linked_list_count++;
        if (linked_list_count > LINKED_LIST_MAX_COUNT) {
            delete impl;
            throw ExceededLinkedListCountException();
        }
        impl->head = nullptr;
        impl->tail = nullptr;
        impl->size = 0;
    }

    LinkedList::LinkedList(const LinkedList& other) : impl(new LinkedListImpl()) {
        linked_list_count++;
        if (linked_list_count > LINKED_LIST_MAX_COUNT) {
            delete impl;
            throw ExceededLinkedListCountException();
        }
        impl->head = nullptr;
        impl->tail = nullptr;
        impl->size = 0;
        Node* current = other.impl->head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    LinkedList& LinkedList::operator=(const LinkedList& other) {
        if (this != &other) {
            Node* current = impl->head;
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            impl->head = impl->tail = nullptr;
            impl->size = 0;
            current = other.impl->head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    LinkedList::~LinkedList() {
        Node* current = impl->head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete impl;
        linked_list_count--;
    }

    void LinkedList::test_for_exceptions(const bool (&arr)[3]) {
        if (arr[0] && impl->size >= LINKED_LIST_MAX_ELEMENT_COUNT)
            throw ExceededElementCountException();
        if (arr[1] && impl->size <= 0)
            throw EmptyLinkedListException();
        if (arr[2] && linked_list_count > LINKED_LIST_MAX_COUNT)
            throw ExceededLinkedListCountException();
    }

    void LinkedList::push_front(int value) {
        bool exceptions[] = {true, false, false};
        test_for_exceptions(exceptions);
        Node* new_node = new Node(value);
        if (!impl->head) {
            impl->head = impl->tail = new_node;
        } else {
            new_node->next = impl->head;
            impl->head->prev = new_node;
            impl->head = new_node;
        }
        impl->size++;
    }

    void LinkedList::push_back(int value) {
        bool exceptions[] = {true, false, false};
        test_for_exceptions(exceptions);
        Node* new_node = new Node(value);
        if (!impl->tail) {
            impl->head = impl->tail = new_node;
        } else {
            new_node->prev = impl->tail;
            impl->tail->next = new_node;
            impl->tail = new_node;
        }
        impl->size++;
    }

    int LinkedList::pop_front() {
        bool exceptions[] = {false, true, false};
        test_for_exceptions(exceptions);
        Node* temp = impl->head;
        int value = temp->data;
        if (impl->head == impl->tail) {
            impl->head = impl->tail = nullptr;
        } else {
            impl->head = impl->head->next;
            impl->head->prev = nullptr;
        }
        delete temp;
        impl->size--;
        return value;
    }

    int LinkedList::pop_back() {
        bool exceptions[] = {false, true, false};
        test_for_exceptions(exceptions);
        Node* temp = impl->tail;
        int value = temp->data;
        if (impl->head == impl->tail) {
            impl->head = impl->tail = nullptr;
        } else {
            impl->tail = impl->tail->prev;
            impl->tail->next = nullptr;
        }
        delete temp;
        impl->size--;
        return value;
    }

    int LinkedList::top() {
        bool exceptions[] = {false, true, false};
        test_for_exceptions(exceptions);
        return impl->head->data;
    }

    int LinkedList::bottom() {
        bool exceptions[] = {false, true, false};
        test_for_exceptions(exceptions);
        return impl->tail->data;
    }

    void LinkedList::print_linked_list() {
        Node* current = impl->head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
