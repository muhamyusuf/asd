#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maksimum ukuran stack

struct Stack {
    int stackArray[MAX_SIZE];
    int top;

    // Create an empty stack
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

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak dapat menghapus elemen." << endl;
            return;
        }

        --top;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }

        cout << "Isi stack:" << endl;

        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << " -> index ke- " << i << endl;
        }

        cout << endl;
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
    int size, numFromUser;

    Stack stack;

    cout << "Tentukan berapa banyak angka yang ingin Anda masukkan ke stack: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Banyak angka melebihi kapasitas maksimum." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> numFromUser;

        stack.push(numFromUser);
    }

    cout << "Elemen teratas: " << stack.peek() << endl;

    stack.printStack();

    cout << "Ukuran stack: " << stack.countStack() << endl;

    return 0;
}
