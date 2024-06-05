#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Fungsi untuk membuat linked list kosong
    void createEmpty() {
        head = nullptr;
    }

    // Fungsi untuk memeriksa apakah linked list kosong
    bool isEmpty() {
        return head == nullptr;
    }

    // Fungsi untuk menambahkan node di awal linked list
    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
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

    // Fungsi untuk menambahkan node setelah node tertentu
    void insertAfter(int prevData, int data) {
        if (isEmpty()) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        do {
            if (temp->data == prevData) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node dengan data " << prevData << " tidak ditemukan." << endl;
    }

    // Fungsi untuk menambahkan node di akhir linked list
    void insertLast(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Fungsi untuk menghapus node pertama
    void deleteFirst() {
        if (isEmpty()) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;
    }

    // Fungsi untuk menghapus node terakhir
    void deleteLast() {
        if (isEmpty()) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;
        Node* previous = nullptr;

        while (last->next != head) {
            previous = last;
            last = last->next;
        }

        if (previous) {
            previous->next = head;
        } else {
            head = nullptr;
        }

        delete last;
    }

    // Fungsi untuk mendapatkan head node
    Node* getHead() {
        return head;
    }
};

int main() {
    CircularLinkedList myList;
    
    myList.createEmpty();
    myList.insertFirst(10);
    myList.insertLast(20);
    myList.insertAfter(10, 15);

    // Melakukan iterasi dan mencetak isi linked list
    Node* current = myList.getHead();
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != myList.getHead());
    cout << endl;

    myList.deleteFirst();
    myList.deleteLast();

    return 0;
}
