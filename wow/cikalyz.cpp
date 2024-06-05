#include <iostream>
using namespace std;

// Definisi struktur untuk node dalam Circular Single Linked List
struct Node {
    int data;
    Node* next;
};

// Inisialisasi kepala linked list
Node* head = nullptr;

// Fungsi untuk memasukkan angka di awal linked list
void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Fungsi untuk memasukkan angka di akhir linked list
void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Fungsi untuk menampilkan data di linked list
void displayCircularLinkedList() {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    cout << "Isi circular linkedlist saat ini:" << endl;
    cout << "\n\n";

    Node* current = head;

    do {
        cout << "(" << current->data << " " << current->next << ") ";

        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    insertFirst(10);
    insertLast(5);
    insertFirst(7);
    insertFirst(2);
    insertLast(99);

    displayCircularLinkedList();

    return 0;
}