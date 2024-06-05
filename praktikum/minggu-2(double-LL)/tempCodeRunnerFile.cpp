#include <iostream>
using namespace std;

struct Node{
    int value;
    
    Node *next;
    Node *prev;
};

Node *initialize(int value){
    Node *newNode = new Node();

    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void doubleLinkedList(Node *&head, Node *&tail, int value){
    Node *newNode = initialize(value);

    if (head == nullptr && tail==nullptr){
        head = newNode;
        tail = newNode;

        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printPassword(Node *head){
    Node *current = head;
    // cout<<current;

    while (current != nullptr){
        cout<<"[("<<current->prev<<") "<<current->value<<" ("<<current->next<<")] ";

        current = current->next;
    }

    cout << endl;
}

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;

    int banyakData,inputFromUser;

    cout<<"Tentukan banyak data yang ingin di inputkan (Angka): "; cin>>banyakData;

    for(int i=0;i<banyakData;i++){
        cout<<"Masukkan angka ke- "<<i+1<<" :"; cin>>inputFromUser;

        doubleLinkedList(head,tail,inputFromUser);
    }

    printPassword(head);

    return 0;
}