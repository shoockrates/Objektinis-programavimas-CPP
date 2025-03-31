#include "LinkedList.h"
#include <sstream>
#include <stdexcept>

namespace myNamespace {

class LinkedList::Impl {
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t elementCount;

    void copyElementsFrom(const Impl& other) {
        Node* current = other.head;
        while (current) {
            append(current->value);
            current = current->next;
        }
    }

public:
    Impl() : head(nullptr), tail(nullptr), elementCount(0) {}

    Impl(const Impl& other) : Impl() {
        copyElementsFrom(other);
    }

    ~Impl() { clear(); }

    bool empty() const { return elementCount == 0; }

    size_t size() const { return elementCount; }

    void append(int value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        elementCount++;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
        elementCount++;
    }

    void removeFront() {
        if (!head) throw EmptyListException();
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        elementCount--;
    }

    bool remove(int value) {
        if (empty()) return false;

        if (head->value == value) {
            removeFront();
            return true;
        }

        Node* current = head;
        while (current->next && current->next->value != value) {
            current = current->next;
        }

        if (!current->next) return false;

        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current;
        delete temp;
        elementCount--;
        return true;
    }

    int front() const {
        if (!head) throw EmptyListException();
        return head->value;
    }

    int back() const {
        if (!tail) throw EmptyListException();
        return tail->value;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        elementCount = 0;
    }

    Impl& operator=(const Impl& other) {
        if (this != &other) {
            clear();
            copyElementsFrom(other);
        }
        return *this;
    }

    bool operator<(const Impl& other) const {
        Node* thisNode = head;
        Node* otherNode = other.head;

        while (thisNode && otherNode) {
            if (thisNode->value < otherNode->value) return true;
            if (thisNode->value > otherNode->value) return false;
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }
        return (thisNode == nullptr) && (otherNode != nullptr);
    }

    bool operator==(const Impl& other) const {
        if (elementCount != other.elementCount) return false;
        
        Node* thisNode = head;
        Node* otherNode = other.head;
        
        while (thisNode) {
            if (thisNode->value != otherNode->value) return false;
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }
        return true;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "LinkedList (" << elementCount << " elements): ";
        
        Node* current = head;
        size_t shown = 0;
        const size_t maxDisplay = 5;
        
        while (current && shown < maxDisplay) {
            ss << current->value;
            if (current->next && shown < maxDisplay - 1) ss << " -> ";
            current = current->next;
            shown++;
        }
        
        if (elementCount > maxDisplay) {
            ss << " ... (" << (elementCount - maxDisplay) << " more)";
        }
        return ss.str();
    }

    int at(int index) const {
        if (index < 0 || index >= elementCount) {
            throw std::out_of_range("Index " + std::to_string(index) + " out of range");
        }
        
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    int find(int value) const {
        Node* current = head;
        int index = 0;
        
        while (current) {
            if (current->value == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }
};

LinkedList::LinkedList() : pImpl(std::make_unique<Impl>()) {}
LinkedList::LinkedList(const LinkedList& other) : pImpl(std::make_unique<Impl>(*other.pImpl)) {}
LinkedList::~LinkedList() = default;

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        pImpl = std::make_unique<Impl>(*other.pImpl);
    }
    return *this;
}

bool LinkedList::empty() const { return pImpl->empty(); }
size_t LinkedList::size() const { return pImpl->size(); }
void LinkedList::append(int value) { pImpl->append(value); }
void LinkedList::prepend(int value) { pImpl->prepend(value); }
LinkedList& LinkedList::operator+=(int value) { append(value); return *this; }
LinkedList& LinkedList::operator-=(int value) { pImpl->remove(value); return *this; }
void LinkedList::removeFront() { pImpl->removeFront(); }
LinkedList& LinkedList::operator<<(int value) { prepend(value); return *this; }
LinkedList& LinkedList::operator!() { pImpl->clear(); return *this; }
int LinkedList::front() const { return pImpl->front(); }
int LinkedList::back() const { return pImpl->back(); }
void LinkedList::clear() { pImpl->clear(); }
int LinkedList::operator[](int index) const { return pImpl->at(index); }
bool LinkedList::operator<(const LinkedList& other) const { return *pImpl < *other.pImpl; }
bool LinkedList::operator==(const LinkedList& other) const { return *pImpl == *other.pImpl; }
bool LinkedList::operator!=(const LinkedList& other) const { return !(*this == other); }
bool LinkedList::operator<=(const LinkedList& other) const { return (*this < other) || (*this == other); }
bool LinkedList::operator>(const LinkedList& other) const { return !(*this <= other); }
bool LinkedList::operator>=(const LinkedList& other) const { return !(*this < other); }
std::string LinkedList::toString() const { return pImpl->toString(); }
int LinkedList::find(int value) const { return pImpl->find(value); }
}
