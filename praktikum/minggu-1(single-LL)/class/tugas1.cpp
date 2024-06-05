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

        void deleteNode(int n) {
            Node* current = head;
            Node* prev = nullptr;

            while (current != nullptr && current->value != n) {
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Maaf, angka yang Anda inputkan tidak ada dalam linked list." << endl;
                return;
            }

            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }

            cout << "Angka " << n << " telah dihapus dari linked list." << endl;
            delete current;
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
    int inputFromUser;

    cout << "Masukkan 5 angka untuk diurutkan: " << endl;

    for (int i = 0; i < 5; i++) {
        cin >> inputFromUser;
        list.insertSorted(inputFromUser);
    }

    list.printLinkedList();

    cout << "Input angka yang ingin dihapus: " << endl;
    cin >> inputFromUser;

    list.deleteNode(inputFromUser);

    cout << "Linked list setelah dihapus: " << endl;
    list.printLinkedList();

    return 0;
}
