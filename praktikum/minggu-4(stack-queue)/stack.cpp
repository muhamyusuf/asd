#include <iostream>
using namespace std;

class initStack {
private:
    int* array;
    int top;
    int capacity;

public:
    initStack(int size) {
        capacity = size;

        array = new int[capacity];

        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    void push(int data) {
        if(isFull()){
            cout << "Stack penuh. Tidak dapat menambahkan elemen lagi." << endl;
            return;
        }

        if (top == capacity - 1) {
            cout << "Stack penuh. Tidak dapat menambahkan elemen lagi." << endl;
            return;
        }

        array[++top] = data;
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
        
        cout << "Isi stack: ";
        for (int i = 0; i <= top; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return -1; // Nilai default jika stack kosong
        }

        return array[top];
    }

    int countStack() {
        return top + 1;
    }
};

int main() {
    int size,numFromUser;

    cout << "Masukkan ukuran stack: "; cin >> size;

    initStack myStack(size);

    for(int i=0; i<size; i++) {
        cout<<"Masukkan angka ke-"<<i+1<<": "; cin>>numFromUser;

        myStack.push(numFromUser);
    }


    cout << "Elemen teratas: " << myStack.peek() << endl;

    myStack.printStack();

    cout << "Ukuran stack: " << myStack.countStack() << endl;

    return 0;
}
