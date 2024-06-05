#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// create a new node
Node* initialize(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// insert node into the tree
Node* insertLeft(Node* node, int value) {
    if (node == nullptr)
        return nullptr;

    node->left = initialize(value);
    return node->left;
}

Node* insertRight(Node* node, int value) {
    if (node == nullptr)
        return nullptr;

    node->right = initialize(value);
    return node->right;
}

// traversal operations
void preOrder(Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node) {
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = initialize(1);

    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);
    insertLeft(root->left->left, 8);

    cout << "Preorder traversal of the constructed tree is\n";
    preOrder(root);

    cout << "\nInorder traversal of the constructed tree is\n";
    inOrder(root);

    cout << "\nPostorder traversal of the constructed tree is\n";
    postOrder(root);

    return 0;
}