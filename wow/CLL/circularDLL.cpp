#include <iostream>
using namespace std;

// Definisi struktur untuk node dalam Circular Double Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Class untuk Circular Double Linked List
class CircularDoubleLinkedList {
private:
    Node* head;

public:
    CircularDoubleLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk memasukkan angka di awal linked list
    void insertFirst(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            Node* tail = head->prev;

            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    // Fungsi untuk memasukkan angka di akhir linked list
    void insertLast(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            Node* tail = head->prev;

            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
        }
    }

    // Fungsi untuk menampilkan data di linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Fungsi untuk menghitung dan menampilkan angka yang duplikat
    void countAndDisplayDuplicates() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* current = head;
        int duplicateCount = 0;

        do {
            Node* temp = current->next;

            while (temp != head) {
                if (temp->data == current->data) {
                    duplicateCount++;
                    cout << current->data << " ";
                    break;
                }
                temp = temp->next;
            }
            current = current->next;
        } while (current != head);

        if (duplicateCount > 0) {
            cout << "Total duplicates: " << duplicateCount << endl;
            cout << endl;
        } else {
            cout << "No duplicates found." << endl;
        }
    }

    // Fungsi untuk menghapus semua angka duplikat
    void removeDuplicates() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            Node* temp = current->next;
            
            while (temp != head) {
                if (temp->data == current->data) {
                    Node* duplicate = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp = temp->next; // Langsung maju ke node berikutnya
                    delete duplicate;
                } else {
                    temp = temp->next;
                }
            }
            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularDoubleLinkedList linkedList;
    int choice, value;

    linkedList.insertFirst(1);
    linkedList.insertFirst(1);
    linkedList.insertFirst(2);
    linkedList.insertFirst(3);
    linkedList.insertLast(5);
    linkedList.insertLast(3);
    linkedList.insertLast(4);

    do {
        cout << "Circular Double Linked List Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Display data" << endl;
        cout << "4. Count and display duplicates" << endl;
        cout << "5. Remove duplicates" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                linkedList.insertFirst(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                linkedList.insertLast(value);
                break;
            case 3:
                linkedList.display();
                break;
            case 4:
                linkedList.countAndDisplayDuplicates();
                break;
            case 5:
                linkedList.removeDuplicates();
                cout << "Duplicates removed." << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}