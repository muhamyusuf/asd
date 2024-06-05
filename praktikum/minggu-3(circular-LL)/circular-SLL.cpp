#include <iostream>
using namespace std;

// Definisi struktur untuk node dalam Circular Single Linked List
struct Node {
    int data;
    Node* next;
};

// Class untuk Circular Single Linked List
class CircularSingleLinkedList {
private:
    Node* head;

public:
    CircularSingleLinkedList() {
        head = nullptr;
    }

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

    void deleteLast() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }

    void deleteFirst(){
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }

    // Fungsi untuk menampilkan data di linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        cout<<"Isi circular linkedlist saat ini:"<<endl;
        cout<<"\n\n";

        Node* current = head;

        do {
            cout <<"[" << current->data << ", pointer nextnya: " << current->next <<"] ";

            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main() {
    CircularSingleLinkedList linkedList;
    
    linkedList.insertFirst(4);
    linkedList.insertFirst(4);
    linkedList.insertLast(10);
    linkedList.insertLast(5);
    linkedList.insertFirst(25);

    linkedList.display();

    return 0;
}
