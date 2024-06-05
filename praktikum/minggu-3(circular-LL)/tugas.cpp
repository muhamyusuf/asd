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

        cout<<"\nIsi circular linkedlist saat ini:"<<endl<<endl;

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
    
    int inputFromUser,size;

    cout << "Tentukan panjang linkedlist yang anda inginkan: "; cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Masukkan angka: "; cin >> inputFromUser;

        if(inputFromUser % 2 == 0){
            linkedList.insertFirst(inputFromUser);
        }else{
            linkedList.insertLast(inputFromUser);
        }
    }

    linkedList.display();

    int choice;

    do{
        cout << "\nPilih operasi yang ingin anda lakukan: " << endl;
        cout << "1. Hapus data di awal" << endl;
        cout << "2. Hapus data di akhir" << endl;
        cout << "3. Keluar Program" << endl;

        cout << "Masukkan pilihan anda: "; cin >> choice;

        switch (choice){
            case 1:
                linkedList.deleteFirst();
                break;
            case 2:
                linkedList.deleteLast();
                break;
            case 3:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan anda tidak valid" << endl;
                break;
        }

        if(choice != 3){
            linkedList.display();
        }
    }while(choice != 3);
    
    return 0;
}
