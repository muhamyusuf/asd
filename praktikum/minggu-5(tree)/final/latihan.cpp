#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
  int info;

  Node *left;
  Node *right;
  Node *parent;
};

Node *Initialize(int value){
  Node *newNode = new Node;

  newNode->info = value;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->parent = nullptr;

  return newNode;
}

bool IsTreeEmpty(Node *P) { return P == nullptr; }

void InsertLeft(Node *P, int value){
  Node *newNode = Initialize(value);

  if (P->left == nullptr){
    newNode->parent = P;
    P->left = newNode;
    cout << "Success insert left node with value " << value << " with " << P->info << " as parrent\n";
  }else{
    cout << "Tree left was declared!";
  }
}

void InsertRight(Node *P, int value){
  Node *newNode = Initialize(value);
  if (P->right == nullptr){
    newNode->parent = P;
    P->right = newNode;
    cout << "Success insert right node with value " << value << " with " << P->info << " as parrent\n";
  }
  else{
    cout << "Tree right was declared!";
  }
}

void PreOrder(Node *P){
  if (IsTreeEmpty(P)){
  }else{
    cout << P->info << " ";
    PreOrder(P->left);
    PreOrder(P->right);
  }
}

void InOrder(Node *P){
  if (IsTreeEmpty(P)){
  }else{
    InOrder(P->left);
    cout << P->info << " ";
    InOrder(P->right);
  }
}

void display(Node *P){
  cout << "<>Pre Order : ";
  PreOrder(P);
  cout << endl;
  cout << "<>In Order : ";
  InOrder(P);
  cout << endl;
}

void displayIndent(Node *P, int level=0){
  if (P != nullptr){
    displayIndent(P->right, level + 1);
    cout << setw(level * 3) << " " << P->info << endl;
    displayIndent(P->left, level + 1);
  }
}

int main(){
  Node *P = Initialize(1);
  InsertLeft(P, 2);
  InsertRight(P, 3);

  InsertLeft(P->left, 4);
  InsertRight(P->left, 5);

  InsertLeft(P->right, 6);
  InsertRight(P->right, 7);

  InsertLeft(P->left->left, 8);

  cout << endl << "Display tree : " << endl;
  display(P);

  cout << "Display tree with indent : " << endl;
  displayIndent(P);

  return 0;
}