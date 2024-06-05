#include <iostream>
using namespace std;

// Definisi struktur untuk node dalam Circular Single Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk memasukkan angka di awal linked list
Node* insertFirst(Node* head, int value) {
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

    return head;
}

// Fungsi untuk memasukkan angka di akhir linked list
Node* insertLast(Node* head, int value) {
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

    return head;
}

// Fungsi untuk menampilkan data di linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    cout << "Isi circular linked list saat ini:" << endl;
    cout << "\n\n";

    Node* current = head;

    do {
        cout << "[" << current->data << ", pointer nextnya: " << current->next << "] ";

        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    Node* head = nullptr;

    head = insertFirst(head, 4);
    head = insertFirst(head, 4);
    head = insertLast(head, 10);
    head = insertLast(head, 5);
    head = insertFirst(head, 25);
    head = insertLast(head, 5);

    display(head);

    return 0;
}
