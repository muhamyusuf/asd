#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maksimum ukuran stack

int stack[MAX_SIZE];
int top = -1;

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

    stack[++top] = value;
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

    cout << "Isi stack: "<<endl;

    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ->index ke- " <<i<<endl;
    }

    cout << endl;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
        return -1; // Nilai default jika stack kosong
    }

    return stack[top];
}

int countStack() {
    return top + 1;
}

int main() {
    int size, numFromUser;

    cout << "Tentukan berapa banyak angka yang inin anda masukan ke stack: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Banyak angka melebihi kapasitas maksimum." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> numFromUser;

        push(numFromUser);
    }

    cout << "Elemen teratas: " << peek() << endl;

    printStack();

    cout << "Ukuran stack: " << countStack() << endl;

    return 0;
}
