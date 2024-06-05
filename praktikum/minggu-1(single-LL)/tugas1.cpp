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

void deleteNode(int n, Node *&head){
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr && current->value != n){
        prev = current;
        current = current->next;
    }

    if (current == nullptr){
        cout << "Maaf, angka yang Anda inputkan tidak ada dalam linked list." << endl;
        return;
    }

    if (prev == nullptr){
        head = current->next;
    }else{
        prev->next = current->next;
    }

    cout << "Angka " << n << " telah dihapus dari linked list. Dengan alamat ";

    delete current;
}

int main(){
    Node *head = nullptr;
    int inputFromUser;

    cout << "Masukkan 5 angka untuk diurutkan: " << endl;

    for (int i = 0; i < 5; i++){
        cin >> inputFromUser;
        insertSorted(head, inputFromUser);
    }

    printLinkedList(head);

    cout << "Input angka yang ingin dihapus: " << endl;
    cin >> inputFromUser;

    deleteNode(inputFromUser, head);

    cout << "Linked list setelah dihapus: " << endl;
    printLinkedList(head);

    // Menghapus seluruh linked list untuk menghindari kebocoran memori.
    while (head != nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
