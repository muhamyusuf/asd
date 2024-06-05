#include <iostream>
using namespace std;

// Struktur Node untuk elemen dalam Circular Double Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Struktur Circular Double Linked List
struct CircularDoubleLinkedList {
    Node* head;

    // Konstruktor untuk menginisialisasi Circular Double Linked List
    CircularDoubleLinkedList() : head(nullptr) {}
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan elemen ke awal Circular Double Linked List
void insertFirst(CircularDoubleLinkedList& list, int value) {
    Node* newNode = createNode(value);

    if (list.head == nullptr) {
        list.head = newNode;
        list.head->next = list.head;
        list.head->prev = list.head;
    } else {
        newNode->next = list.head;
        newNode->prev = list.head->prev;
        list.head->prev->next = newNode;
        list.head->prev = newNode;
        list.head = newNode;
    }
}

// Fungsi untuk menambahkan elemen ke akhir Circular Double Linked List
void insertLast(CircularDoubleLinkedList& list, int value) {
    Node* newNode = createNode(value);

    if (list.head == nullptr) {
        list.head = newNode;
        list.head->next = list.head;
        list.head->prev = list.head;
    } else {
        newNode->next = list.head;
        newNode->prev = list.head->prev;
        list.head->prev->next = newNode;
        list.head->prev = newNode;
    }
}

// Fungsi untuk menampilkan Circular Double Linked List
void displayList(CircularDoubleLinkedList& list) {
    if (list.head == nullptr) {
        cout << "Circular Double Linked List kosong." << endl;
        return;
    }

    Node* current = list.head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != list.head);
    cout << endl;
}

int main() {
    CircularDoubleLinkedList myList;

    // Menambahkan elemen ke awal dan akhir Circular Double Linked List
    insertFirst(myList, 30);
    insertFirst(myList, 20);
    insertFirst(myList, 10);

    insertLast(myList, 40);
    insertLast(myList, 50);

    // Menampilkan Circular Double Linked List
    cout << "Circular Double Linked List setelah insert first dan insert last:" << endl;
    displayList(myList);

    return 0;
}
