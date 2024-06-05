#include<iostream>
#include<iomanip> //untuk indentasi

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

// create a new node
Node* createNode(int value) {
    Node* newNode = new Node();

    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }

    newNode->data = value;
    newNode->left = newNode->right = newNode->parent= nullptr;

    return newNode;
}

bool isTreeEmpty(Node* node) {
    return node == nullptr;
}

// insert node into the tree
void insertLeft(Node* node, int value) {
    Node *newNode = createNode(value);

    if(node->left != nullptr){
        newNode->parent = node;
        node->left = newNode;
        cout<<"Success insert left node with value "<<value<<" with "<<node->data<<" as parrent\n";
    }else{
        cout<<"Tree left terisi!\n";
    }
}

void insertRight(Node* node, int value) {
    Node *newNode = createNode(value);

    if(node->right != nullptr){
        newNode->parent = node;
        node->right = newNode;
        cout<<"Success insert right node with value "<<value<<" with "<<node->data<<" as parrent\n";
    }else{
        cout<<"Tree right terisi!\n";
    }
}

// traversal operations
void preOrder(Node* node) {
    if(isTreeEmpty(node))
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node) {
    if(isTreeEmpty(node))
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node) {
    if(isTreeEmpty(node))
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void display(Node* node) {
    if (node == nullptr)
        return;

    // Menampilkan simpul saat ini dengan indentasi
    cout << "Pre Order : ";
    preOrder(node);
    cout << endl;

    cout << "In Order : ";
    inOrder(node);
    cout << endl;

    cout << "Post Order : ";
    postOrder(node);
    cout << endl << endl;
}

void deleteRightLeaf(Node *node){
    if(node->right == nullptr && node->left == nullptr){
       if(node->parent->right != nullptr){
           node->parent->right = nullptr;
           return;
       }

       if(node->parent->left != nullptr){
           node->parent->left = nullptr;
       }
    }

    if(node->right != nullptr && node->left == nullptr){
        deleteRightLeaf(node->right);
    }else if(node->right == nullptr && node->left != nullptr){
        deleteRightLeaf(node->left);
    }else if(node->right != nullptr && node->left != nullptr){
        deleteRightLeaf(node->right);
    }
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

    cout<<"Output : \n";
    display(root);

    cout<<"Processing delete : \n";

    while(!isTreeEmpty(root)){
        deleteRightLeaf(root);
        display(root);
    }

    cout<<"Succes delete data tree\n";

    return 0;
}