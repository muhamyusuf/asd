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

    void push(int data) {
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

    bool isEmpty() {
        return top == -1;
    }

    int countStack() {
        return top + 1;
    }

    
};

int main() {
    initStack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(3);
    myStack.push(3);

    cout << "Elemen teratas: " << myStack.peek() << endl;

    myStack.printStack();

    myStack.pop();
    myStack.pop();

    cout << "Ukuran stack: " << myStack.countStack() << endl;


    return 0;
}
