#include <iostream>
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

    if (*head == nullptr) {
        *head = nodeNew;
        return;
    }

    nodeNew->next = (*head)->next;
    (*head)->next = nodeNew;
}

void printPassword(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << endl;
}

void sortingLinkedList(int n, LL* head) {
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

int main() {
    int inputFromUser;
    Node* head = nullptr;

    cout << "Masukkan 5 angka untuk diurutkan: " << endl;

    for (int i = 0; i < 5; i++) {
        cin >> inputFromUser;

        sortingLinkedList(inputFromUser, &head);
    }

    printPassword(head);

    return 0;
}
