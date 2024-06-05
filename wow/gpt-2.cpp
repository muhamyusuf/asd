#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void append(char data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void encrypt() {
        if (size < 6) {
            cout << "Password harus memiliki minimal 6 karakter!" << endl;
            return;
        }

        Node* newHead = tail->prev->prev->prev->next; // Simpan node yang akan menjadi head baru
        char key = 'X'; // Karakter kunci

        tail->prev->prev->prev->next = head;
        head->prev = tail->prev->prev->prev;

        tail->prev = newHead;
        newHead->next = tail;

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = newHead->next;
        newNode->prev = newHead;
        newHead->next->prev = newNode;
        newHead->next = newNode;

        size++;
    }

    void decrypt() {
        if (size < 6) {
            cout << "Password harus memiliki minimal 6 karakter!" << endl;
            return;
        }

        Node* newHead = head->next;
        char key = tail->data;

        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;

        head->prev = tail;
        tail->next = head;

        newHead->prev = nullptr;
        head = newHead;

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = newHead;
        newNode->prev = nullptr;
        newHead->prev = newNode;
        head = newNode;

        size--;
    }

    void display(string user) {
        if (size == 0) {
            cout << "Password kosong!" << endl;
            return;
        }

        cout << "Password: ";

        if (user == "admin") {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
        } else if (user == "anonymous") {
            Node* current = tail;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->prev;
            }
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList password;
    string user = "anonymous"; // Default user type

    cout << "Program Enkripsi & Dekripsi Password\n";

    string input;
    cout << "Masukkan password (minimal 6 karakter): ";
    cin >> input;

    for (char c : input) {
        password.append(c);
    }

    char choice;
    do {
        cout << "----------------------\n";
        cout << "Menu\n";
        cout << "Role: " << user << endl;
        cout << "----------------------\n";
        cout << "1. Tampilkan password\n";
        cout << "2. Enkripsi password\n";
        cout << "3. Dekripsi password\n";
        cout << "4. Ganti user role (admin/anonymous)\n";
        cout << "5. Keluar program\n";
        cout << "----------------------\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case '1':
                password.display(user);
                break;
            case '2':
                password.encrypt();
                cout << "Password berhasil dienkripsi!" << endl;
                break;
            case '3':
                password.decrypt();
                break;
            case '4':
                cout << "Ganti user role (admin/anonymous): ";
                cin >> user;
                break;
            case '5':
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi!" << endl;
        }
    } while (choice != '5');

    return 0;
}
