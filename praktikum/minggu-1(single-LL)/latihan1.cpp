// Muhammad Yusuf
// 122140193

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

Node *initialize(int value){
    Node *newNode = new Node();

    newNode->value = value;
    newNode->next = nullptr;

    return newNode;
}

void insertSorted(Node *&head, int value){
    Node *newNode = initialize(value);

    if (head == nullptr || value <= head->value){
        newNode->next = head;
        head = newNode;
        
        return;
    }

    Node *current = head;

    while (current->next != nullptr && current->next->value < value){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printLinkedList(const Node *head){
    const Node *current = head;

    while (current != nullptr){
        cout << current->value << " (" << current->next << ") ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    Node *head = nullptr;

    cout << "Masukkan 5 angka untuk diurutkan: " << endl;

    for (int i = 0; i < 5; i++){
        int inputFromUser;
        cin >> inputFromUser;
        insertSorted(head, inputFromUser);
    }

    printLinkedList(head);

    // Menghapus seluruh linked list untuk menghindari kebocoran memori.
    while (head != nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
