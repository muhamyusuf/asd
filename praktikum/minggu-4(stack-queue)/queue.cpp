#include <iostream>
using namespace std;

class Queue {
private:
    int* array;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Antrian penuh. Tidak dapat menambahkan elemen lagi." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        array[++rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong. Tidak dapat menghapus elemen." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            ++front;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return -1; // Nilai default jika antrian kosong
        }
        return array[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    void display(){
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }
        cout << "Isi antrian: ";

        for (int i = front; i <= rear; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Elemen pertama: " << myQueue.peek() << endl;

    myQueue.dequeue();

    cout << "Ukuran antrian: " << myQueue.size() << endl;

    myQueue.display();

    return 0;
}
