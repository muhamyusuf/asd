#include<iostream>
using namespace std;

typedef struct Node* LL;

struct Node {
    int value;
    Node* next;
};

Node* createEmpty() {
    Node* emptyNode = new Node(); // alokasi
    return emptyNode;
}

void addAfter(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == nullptr) {
        *head = nodeNew;
        return;
    }

    nodeNew->next = (*head)->next;
    (*head)->next = nodeNew;
}

void addBefore(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == nullptr) {
        *head = nodeNew;
        return;
    }

    nodeNew->next = *head;
    *head = nodeNew;
}

void addTail(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == nullptr) {
        *head = nodeNew;
        return;
    }

    Node* current = *head;

    while(current->next != nullptr) {
        current = current->next;
    }

    current->next = nodeNew;
}

void printPassword(Node* head) {
    Node* current = head;
    
    while(current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << endl;
}

void deleteNode(int value, LL* head) {
    if (*head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* current = *head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (prev == nullptr) {
                // Node yang akan dihapus adalah head
                *head = current->next;
            } else {
                // Node yang akan dihapus adalah bukan head
                prev->next = current->next;
            }
            delete current; // Hapus node
            cout << "Node dengan nilai " << value << " telah dihapus." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
}


void deleteLinkedList(LL* head) {
    Node* current = *head;
    Node* next;

    while(current != nullptr) {
        next = current->next;
        delete current; // Hapus node saat ini
        current = next;
    }

    *head = nullptr; // Atur head ke NULL untuk menandakan linked list kosong
}

void insertSorted(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if (*head == nullptr || n < (*head)->value) {
        nodeNew->next = *head;
        *head = nodeNew;
        return;
    }

    Node* current = *head;
    Node* prev = nullptr;

    while (current != nullptr && current->value < n) {
        prev = current;
        current = current->next;
    }

    prev->next = nodeNew;
    nodeNew->next = current;
}

void inputFrom(int n, LL* head) {
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertSorted(value, head);
    }
}

int main() {
    Node* head = nullptr;

    addAfter(5, &head);
    addAfter(10, &head);
    addAfter(3, &head);
    addBefore(11, &head);
    addTail(100, &head);

    printPassword(head);

    return 0;
}