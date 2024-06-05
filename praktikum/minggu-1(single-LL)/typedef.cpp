#include <iostream>
using namespace std;

typedef struct Node
{
    int value;
    Node *next;
} NodeLinkedList;

int main()
{
    NodeLinkedList *head = nullptr;

    NodeLinkedList *newNode = new NodeLinkedList();
    newNode->value = 10;
    newNode->next = nullptr;

    cout << newNode->value << endl;
}