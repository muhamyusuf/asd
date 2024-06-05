#include<iostream>
#include<iomanip> //untuk indentasi

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// create a new node
Node* createNode(int value) {
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

    node->left = createNode(value);

    cout<<"Success insert left node with value "<<value<<" with "<<node->data<<" as parrent\n";

    return node->left;
}

Node* insertRight(Node* node, int value) {
    if (node == nullptr)
        return nullptr;

    node->right = createNode(value);

    cout<<"Success insert right node with value "<<value<<" with "<<node->data<<" as parrent\n";

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

void display(Node* node, int indent = 0) {
    if (node == nullptr)
        return;

    // Menampilkan simpul saat ini dengan indentasi
    cout << setw(indent) << node->data << "\n";

    // Mencetak anak kanan dengan indentasi yang sama dengan anak kiri
    display(node->right, indent + 4);

    // Mencetak anak kiri dengan indentasi yang lebih dalam
    display(node->left, indent + 4);
}

int main() {
    Node* root = createNode(1);

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

    cout << "\nDisplay the tree\n";
    display(root);

    return 0;
}