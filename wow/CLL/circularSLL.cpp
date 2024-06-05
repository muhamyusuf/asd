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
        int count = 0;
        int duplicateCount = 0;
        int previousData = -1;

        do {
            if (current->data == previousData) {
                duplicateCount++;
            } else {
                previousData = current->data;
            }

            count++;
            current = current->next;
        } while (current != head);

        if (duplicateCount > 0) {
            cout << "Total duplicates: " << duplicateCount << endl;
            cout << "Duplicate numbers: ";
            current = head;
            do {
                int data = current->data;
                Node* temp = current->next;
                while (temp != head) {
                    if (temp->data == data) {
                        cout << data << " ";
                        break;
                    }
                    temp = temp->next;
                }
                current = current->next;
            } while (current != head);
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
            Node* temp = current;
            Node* inner = current->next;
            
            while (inner != head) {
                if (inner->data == current->data) {
                    temp->next = inner->next;
                    Node* duplicate = inner;
                    inner = inner->next;
                    delete duplicate;
                } else {
                    temp = inner;
                    inner = inner->next;
                }
            }

            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularSingleLinkedList linkedList;
    int choice, value;

    linkedList.insertFirst(1);
    linkedList.insertFirst(1);
    linkedList.insertFirst(3);
    linkedList.insertFirst(3);
    linkedList.insertFirst(4);
    linkedList.insertFirst(4);
    linkedList.insertFirst(4);
    linkedList.insertFirst(5);
    linkedList.insertFirst(5);
    linkedList.insertFirst(5);    


    do {
        cout << "Circular Single Linked List Menu:" << endl;
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