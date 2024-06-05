#include <iostream>
using namespace std;

struct Node {
  int info;
  
  Node *left;
  Node *right;
  Node *parent;
};

Node *Initialize(int input) {
  Node *newNode = new Node;
  newNode->info = input;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->parent = nullptr;
  return newNode;
}

bool IsTreeEmpty(Node *P) { return P == nullptr; }

void InsertLeft(Node *P, int input) {
  Node *newNode = Initialize(input);
  if (P->left == nullptr) {
    newNode->parent = P;
    P->left = newNode;
    cout << "Berhasil melakukan insert left " << input
         << " di parent : " << P->info << endl;
  } else {
    cout << "Tree left terisi!";
  }
}

void InsertRight(Node *P, int input) {
  Node *newNode = Initialize(input);
  if (P->right == nullptr) {
    newNode->parent = P;
    P->right = newNode;
    cout << "Berhasil melakukan insert right " << input
         << " di parent : " << P->info << endl;
  } else {
    cout << "Tree right terisi!";
  }
}

void PreOrder(Node *P) {
  if (IsTreeEmpty(P)) {

  } else {
    cout << P->info << " ";
    PreOrder(P->left);
    PreOrder(P->right);
  }
}

void InOrder(Node *P) {
  if (IsTreeEmpty(P)) {

  } else {
    InOrder(P->left);
    cout << P->info << " ";
    InOrder(P->right);
  }
}

void PostOrder(Node *P) {
  if (IsTreeEmpty(P)) {

  } else {
    PostOrder(P->left);
    PostOrder(P->right);
    cout << P->info << " ";
  }
}

void tampilkan(Node *P){
    cout << "<>Pre Order : ";
    PreOrder(P);
    cout << endl;
    cout << "<>In Order : ";
    InOrder(P);
    cout << endl;
    cout << "<>Post Order : ";
    PostOrder(P);
    cout << endl <<endl;
}

void DeleteRightLeaf(Node *P){
    if(P->right == nullptr && P->left == nullptr){
       if(P->parent->right != nullptr){
           P->parent->right = nullptr;
           return;
       }

       if(P->parent->left != nullptr){
           P->parent->left = nullptr;
       }
    }

    if(P->right != nullptr && P->left == nullptr){
        DeleteRightLeaf(P->right);
    }else if(P->right == nullptr && P->left != nullptr){
        DeleteRightLeaf(P->left);
    }else if(P->right != nullptr && P->left != nullptr){
        DeleteRightLeaf(P->right);
    }


}


int main() {
  Node *P = Initialize(1);
  InsertLeft(P, 2);
  InsertRight(P, 3);

  InsertLeft(P->left, 4);
  InsertRight(P->left, 5);

  InsertLeft(P->right, 6);
  InsertRight(P->right, 7);

  InsertLeft(P->left->left, 8);

  cout<<endl<<"OUTPUT : " <<endl;
  tampilkan(P);


  cout<<"DELETE TREE: " << endl;
  while(!IsTreeEmpty(P)){
      DeleteRightLeaf(P);
      tampilkan(P);
  }

    cout<<"Success delete tree";

  return 0;
}