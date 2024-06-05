#include <iostream>
#include <cctype> //untuk cek jenis karakter
using namespace std;

const int MAX_SIZE = 100; // Maksimum ukuran stack

struct Stack {
    int stackArray[MAX_SIZE];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh. Tidak dapat menambahkan elemen lagi." << endl;
            return;
        }

        stackArray[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak dapat menghapus elemen." << endl;
            return -1;
        }

        return stackArray[top--];
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }

        cout << "Isi stack:" << endl;

        for (int i = top; i >= 0; i--) {
            int poppedValue = pop(); // Pop karakter dari stack
            cout << poppedValue << " -> index ke- " << i << " (" << char(poppedValue) << ")" << endl;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return -1; // Nilai default jika stack kosong
        }

        return stackArray[top];
    }

    int countStack() {
        return top + 1;
    }
};

int main() {
    string input;
    Stack stack;

    cout << "Masukkan sebuah string: ";
    cin>>input;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (isupper(c)) {
            stack.push(int(c));
        } else if (isdigit(c)) {
            int poppedValue = stack.pop();

            if (poppedValue != -1) {
                cout << "POP: " << poppedValue << " (" << char(poppedValue) << ")" << endl;
            }
        }
    }

    stack.printStack(); // Pop dan cetak karakter yang tersisa
    return 0;
}
