#include <iostream>
using namespace std;

struct Node {
    int value;
    
    Node* next;
    Node* prev;
};

struct List {
    Node* head=nullptr;
    Node* tail=nullptr;
};

Node *initialize(int value);
void insertSorted(List& list, int value);
void printDoubleLinkedList(Node* head);

int main() {
    List list;
    int banyakData, inputFromUser;

    cout << "Tentukan banyak data yang ingin diinputkan (Angka): ";
    cin >> banyakData;

    for (int i = 0; i < banyakData; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> inputFromUser;

        insertSorted(list, inputFromUser);
    }

    printDoubleLinkedList(list.head);

    // Delete all nodes to prevent memory leak
    while (list.head != nullptr) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }

    return 0;
}

Node* initialize(int value) {
    Node* newNode = new Node;

    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void insertSorted(List& list, int value) {
    Node* newNode = initialize(value);

    if (!list.head) {
        list.head = newNode;
        list.tail = newNode;
    }else if (value <= list.head->value) {
        newNode->next = list.head;
        list.head->prev = newNode;
        list.head = newNode;
    }else if (value >= list.tail->value) {
        newNode->prev = list.tail;
        list.tail->next = newNode;
        list.tail = newNode;
    }else {
        Node* current = list.head;

        while (current->next->value < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

void printDoubleLinkedList(Node* head) {
    Node* current = head;

    while (current) {
        cout << "[" << current->prev << " " << current->value << " " << current->next << "] ";
        current = current->next;
    }
    
    cout << endl;
}
