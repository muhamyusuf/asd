#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    string position;
};

typedef struct Node *NodePtr;

struct Node {
    Employee data;
    NodePtr left, right, parent;
};

NodePtr root;

NodePtr createNode(Employee employee) {
    NodePtr newNode = new Node();
    newNode->data = employee;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    return newNode;
}

void createTree(Employee employee) {
    if (root != nullptr) {
        cout << "Root already exists. Cannot create a new root." << endl;
    } else {
        root = createNode(employee);
        cout << "Root node created with employee: " << employee.name << ", " << employee.position << endl;
    }
}

NodePtr insertLeftChild(Employee employee, NodePtr parentNode) {
    if (parentNode->left != nullptr) {
        cout << "Failed to insert left child. Left child already exists for node with employee: " << parentNode->data.name << ", " << parentNode->data.position << endl;
        return nullptr;
    } else {
        NodePtr newNode = createNode(employee);
        parentNode->left = newNode;
        newNode->parent = parentNode;
        cout << "Left child with employee: " << employee.name << ", " << employee.position << " added for node with employee: " << parentNode->data.name << ", " << parentNode->data.position << endl;
        return newNode;
    }
}

NodePtr insertRightChild(Employee employee, NodePtr parentNode) {
    if (parentNode->right != nullptr) {
        cout << "Failed to insert right child. Right child already exists for node with employee: " << parentNode->data.name << ", " << parentNode->data.position << endl;
        return nullptr;
    } else {
        NodePtr newNode = createNode(employee);
        parentNode->right = newNode;
        newNode->parent = parentNode;
        cout << "Right child with employee: " << employee.name << ", " << employee.position << " added for node with employee: " << parentNode->data.name << ", " << parentNode->data.position << endl;
        return newNode;
    }
}

void inorderTraversal(NodePtr currentNode = root) {
    if (!root) {
        cout << "Tree is empty!" << endl;
    } else {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            cout <<"{"<< currentNode->data.name << ", " << currentNode->data.position << "}, ";
            inorderTraversal(currentNode->right);
        }
    }
}

void postorderTraversal(NodePtr currentNode = root) {
    if (!root) {
        cout << "Tree is empty!" << endl;
    } else {
        if (currentNode != nullptr) {
            postorderTraversal(currentNode->left);
            postorderTraversal(currentNode->right);
            cout <<"{"<< currentNode->data.name << ", " << currentNode->data.position << "}, ";
        }
    }
}

void deleteTree(NodePtr currentNode) {
    if (currentNode == nullptr) {
        return;
    } else {
        deleteTree(currentNode->left);
        deleteTree(currentNode->right);
        cout << endl << "Deleting node with employee: " << currentNode->data.name << ", " << currentNode->data.position;
        delete currentNode;
    }
}

void clearTree() {
    deleteTree(root);
    cout << endl << "Tree deleted." << endl;
}

void printTreeStructure(NodePtr root, int space) {
    if (root == nullptr) {
        return;
    }

    space += 20;

    printTreeStructure(root->right, space);

    cout<<endl;

    for (int i = 20; i < space; i++) {
        cout << " ";
    }
    cout << root->data.name << ", " << root->data.position << "\n";
    printTreeStructure(root->left, space);
}

int main() {
    NodePtr node2, node3, node4, node5, node6, node7;

    createTree({"CEO", "John Doe"});
    node2 = insertLeftChild({"CTO", "Alice Smith"}, root);
    node3 = insertRightChild({"CFO", "Bob Johnson"}, root);
    node4 = insertLeftChild({"Lead Engineer", "Charlie Brown"}, node2);
    node5 = insertRightChild({"Software Developer", "Diana Miller"}, node2);
    node6 = insertRightChild({"Financial Analyst", "Eva Wilson"}, node3);
    node7 = insertLeftChild({"HR Manager", "Frank Davis"}, node3);

    cout << "\nTree Structure:" << endl;
    printTreeStructure(root, 0);

    cout << endl << "Inorder traversal: " << endl;
    inorderTraversal();

    cout<<endl;

    cout << endl << "Postorder traversal: " << endl;
    postorderTraversal();

    cout << endl << endl;
    clearTree();
    return 0;
}
