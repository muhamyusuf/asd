#include <iostream>
using namespace std;

// Struktur untuk node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam linked list terurut
void insertSorted(Node*& head, int value) {
    Node* newNode = createNode(value);

    // Kasus jika linked list masih kosong atau nilai baru lebih kecil dari head
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Menemukan tempat yang tepat untuk menyisipkan node
    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    // Menyisipkan node baru setelah current
    newNode->next = current->next;
    current->next = newNode;
}

// Fungsi untuk menampilkan isi linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int input;

    cout << "Masukkan angka (integer) atau -1 untuk selesai: ";

    while (true) {
        cin >> input;

        // Selesai jika input -1
        if (input == -1) {
            break;
        }

        // Memasukkan data ke dalam linked list secara terurut
        insertSorted(head, input);

        // Menampilkan isi linked list
        cout << "Linked List saat ini: ";
        displayList(head);

        cout << "Masukkan angka (integer) atau -1 untuk selesai: ";
    }

    return 0;
}
