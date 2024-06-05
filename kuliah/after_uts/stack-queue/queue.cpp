#include <iostream>

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
            std::cout << "Antrian penuh. Tidak dapat menambahkan elemen lagi." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        array[++rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong. Tidak dapat menghapus elemen." << std::endl;
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
            std::cout << "Antrian kosong." << std::endl;
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
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Elemen pertama: " << myQueue.peek() << std::endl;

    myQueue.dequeue();

    std::cout << "Ukuran antrian: " << myQueue.size() << std::endl;

    return 0;
}
