#include "LinkedList.h"
#include <iostream>

using namespace myNamespace;
using namespace std;

int main() {
    try {
        cout << "=== Linked List Demonstration ===" << endl << endl;
        
        LinkedList primaryList;
        cout << "Initialized empty list: " << primaryList.toString() << endl;
        
        cout << "\nAppending values 100, 200, 300..." << endl;
        primaryList.append(100);
        primaryList.append(200);
        primaryList.append(300);
        cout << "Updated list: " << primaryList.toString() << endl;
        cout << "First element: " << primaryList.front() << endl;

        cout << "\nAdding 500 using += operator..." << endl;
        primaryList += 500;
        cout << "Result: " << primaryList.toString() << endl;
        
        cout << "\nSearching for values:" << endl;
        cout << "Position of 200: " << primaryList.find(200) << endl;
        cout << "Position of 999 (not present): " << primaryList.find(999) << endl;
        
        cout << "\nPrepending 250 using << operator..." << endl;
        primaryList << 250;
        cout << "Updated list: " << primaryList.toString() << endl;

        cout << "\nCreating copy via copy constructor..." << endl;
        LinkedList copiedList(primaryList);
        cout << "Original: " << primaryList.toString() << endl;
        cout << "Copy:     " << copiedList.toString() << endl;

        cout << "\nAssigning primary list to temporary list..." << endl;
        LinkedList tempList;
        tempList.append(500);
        tempList.append(600);
        cout << "Temporary list before assignment: " << tempList.toString() << endl;
        tempList = primaryList;
        cout << "Temporary list after assignment: " << tempList.toString() << endl;

        cout << "\nprimary == copied: " << (primaryList == copiedList ? "Equal" : "Different") << endl;
        cout << "primary == temp:   " << (primaryList == tempList ? "Equal" : "Different") << endl;
        
        cout << "\nModifying copied list by removing first element..." << endl;
        copiedList.removeFront();
        cout << "primary > copied: " << (primaryList > copiedList ? "True" : "False") << endl;

        cout << "\nOriginal list: " << primaryList.toString() << endl;
        
        cout << "\nRemoving elements from front:" << endl;
        while (!primaryList.empty()) {
            cout << "Removing: " << primaryList.front() << endl;
            primaryList.removeFront();
            cout << "Remaining elements: " << primaryList.toString() << endl;
        }

        cout << "\nCopied list before clear: " << copiedList.toString() << endl;
        cout << "Using ! operator to clear..." << endl;
        !copiedList;
        cout << "Copied list after clear: " << copiedList.toString() << endl;

        LinkedList listArray[3];
        for (int listIdx = 0; listIdx < 3; ++listIdx) {
            cout << "Populating list " << listIdx << "..." << endl;
            for (int val = 0; val < 3; ++val) {
                listArray[listIdx].append(listIdx * 10 + val);
            }
            cout << "List " << listIdx << ": " << listArray[listIdx].toString() << endl;
        }

    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    } catch (...) {
        cout << "\nUnknown error occurred" << endl;
    }

    cout << "\n=== Demonstration Complete ===" << endl;
    return 0;
}
