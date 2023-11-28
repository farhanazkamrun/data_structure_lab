#include <iostream>

using namespace std;

struct Node {

    int data;

    Node* next;

    Node(int val) : data(val), next(nullptr) {}

};

class LinkedList {

private:

    Node* head;

public:

    LinkedList() : head(nullptr) {}

    void insert(int val) {

        Node* newNode = new Node(val);

        if (head == nullptr) {

            head = newNode;

        } else {

            Node* current = head;

            while (current->next != nullptr) {

                current = current->next;

            }

            current->next = newNode;

        }

        cout << "Inserted: " << val << endl;

    }

   void remove(int val) {

        Node* current = head;

        Node* prev = nullptr;

        while (current != nullptr && current->data != val) {

            prev = current;

            current = current->next;

        }

        if (current == nullptr) {

            cout << "Value not found, cannot delete." << endl;

            return;

        }

        if (prev == nullptr) {

            head = current->next;

        } else {

            prev->next = current->next;

        }

        cout << "Deleted: " << val << endl;

        delete current;

    }

    bool search(int val) {

        Node* current = head;

        while (current != nullptr) {

            if (current->data == val) {

                cout << "Found: " << val << endl;

                return true;

            }

            current = current->next;

        }

        cout << "Not Found: " << val << endl;

        return false;

    }

};

int main() {

    LinkedList myList;

    myList.insert(10);

    myList.insert(20);

    myList.insert(30);

    myList.search(22);

    myList.search(42);

    myList.remove(24);

    myList.search(26);

    return 0;
}
