#include <iostream>
using namespace std;

// Struktur Node untuk elemen dalam Circular Double Linked List
struct Node {
    string data;
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
Node* createNode(string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan elemen ke awal Circular Double Linked List
void insertFirst(CircularDoubleLinkedList& list, string value) {
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
void insertLast(CircularDoubleLinkedList& list, string value) {
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

// Fungsi untuk menghapus elemen dari awal Circular Double Linked List
void deleteFirst(CircularDoubleLinkedList& list) {
    if (list.head == nullptr) {
        cout << "Circular Double Linked List kosong. Tidak dapat menghapus elemen." << endl;
        return;
    }

    Node* temp = list.head;

    if (list.head->next == list.head) {
        list.head = nullptr;
    } else {
        list.head->prev->next = list.head->next;
        list.head->next->prev = list.head->prev;
        list.head = list.head->next;
    }

    delete temp;
}

// Fungsi untuk menghapus elemen dari akhir Circular Double Linked List
void deleteLast(CircularDoubleLinkedList& list) {
    if (list.head == nullptr) {
        cout << "Circular Double Linked List kosong. Tidak dapat menghapus elemen." << endl;
        return;
    }

    Node* temp = list.head->prev;

    if (temp == list.head) {
        list.head = nullptr;
    } else {
        temp->prev->next = list.head;
        list.head->prev = temp->prev;
    }

    delete temp;
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
    insertFirst(myList, "Alice");
    insertFirst(myList, "Bob");
    insertFirst(myList, "Carlos");
    insertLast(myList, "David");
    insertLast(myList, "Carlos");

    // Menampilkan Circular Double Linked List
    cout << "Circular Double Linked List setelah insert first dan insert last:" << endl;
    displayList(myList);

    // Menghapus elemen dari awal dan akhir Circular Double Linked List
    deleteFirst(myList);

    // Menghapus elemen terakhir jika namanya "Carlos"
    if (myList.head != nullptr && myList.head->prev->data == "Carlos") {
        deleteLast(myList);
    }

    // Menampilkan Circular Double Linked List setelah delete first dan delete last (jika Carlos)
    cout << "Circular Double Linked List setelah delete first dan delete last (jika Carlos):" << endl;
    displayList(myList);

    return 0;
}
