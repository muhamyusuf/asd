#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void printIndented(Node *node, int depth)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        std::cout << "  ";
    }
    std::cout << node->data << std::endl;

    printIndented(node->left, depth + 1);
    printIndented(node->right, depth + 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->left->left->right->right = new Node(11);
    root->left->right = new Node(3);
    root->left->right->left = new Node(0);
    root->right = new Node(1);
    root->right->left = new Node(15);
    root->right->left->left = new Node(16);
    root->right->left->left->left = new Node(18);
    root->right->right = new Node(9);
    root->right->right->left = new Node(20);
    root->right->right->left->right = new Node(13);

    printIndented(root, 0);

    return 0;
}
