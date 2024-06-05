#include <iostream>
#define MAX 50
using namespace std;

struct Stack {
    int biner[MAX];
    int top;
} stack;

void CreateEmpty() {
    stack.top = -1;
}

bool isEmpty() {
    return stack.top == -1;
}

bool isFull() {
    return stack.top == MAX - 1;
}

void Push(int x) {
    if (!isFull()) {
        stack.top++;
        stack.biner[stack.top] = x;
    } else {
        cout << "Stack penuh. Tidak dapat menambahkan elemen lagi." << endl;
    }
}

void Pop() {
    if (!isEmpty()) {
        stack.top--;
    } else {
        cout << "Stack kosong." << endl;
    }
}

void convertToBinary(int n) {
    while (n > 0) {
        Push(n % 2);
        n = n / 2;
    }
}

void nimbagi2(int n) {
    while (stack.top < 9) {
        Push(n / 2);
        n = n / 2;
    }
}

void printStack() {
    while (!isEmpty()) {
        cout << stack.biner[stack.top] << " ";
        Pop();
    }
}

int main() {
    int nim;
    CreateEmpty();
    string role;

    cout << "Pilih peran (admin/anonymous): ";
    cin >> role;

    int choice;
    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Konversi ke Binary" << endl;
        cout << "2. Bagi 2" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                if (role == "admin") {
                    cout << "Representasi biner dari NIM: ";
                    convertToBinary(nim);
                } else if (role == "anonymous") {
                    cout << "Representasi biner dari NIM: ";
                    while (stack.top < 26) {
                    Push(rand() % 2);
                    }
                }
                printStack();
                cout << endl << endl;
                break;
            case 2:
                cout << "Masukkan NIM: ";
                cin >> nim;
                if (role == "admin") {
                    cout << "Hasil pembagian NIM dengan 2: ";
                    nimbagi2(nim);
                } else if (role == "anonymous") {
                    cout << "Hasil pembagian NIM dengan 2: ";
                    while (stack.top < 9) {
                    Push(rand());
                    }
                }
                printStack();
                cout << endl << endl;
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}