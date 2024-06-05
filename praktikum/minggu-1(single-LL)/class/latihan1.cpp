#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
    public:
        Node* head;

        LinkedList() : head(nullptr) {}

        void insertSorted(int value) {
            Node* newNode = new Node(value);

            if (head == nullptr || value <= head->value) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* current = head;

            while (current->next != nullptr && current->next->value < value) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        void printLinkedList() {
            Node* current = head;

            while (current != nullptr) {
                cout << " [" << current->value << " | (" << current->next << ")] ";

                current = current->next;
            }
            cout << endl;
        }

        ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    cout << "Masukkan 5 angka untuk diurutkan: " << endl;

    for (int i = 0; i < 5; i++) {
        int inputFromUser;
        cin >> inputFromUser;

        list.insertSorted(inputFromUser);
    }

    list.printLinkedList();

    return 0;
}
