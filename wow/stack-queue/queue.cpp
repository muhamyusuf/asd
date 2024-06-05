#include <iostream>
#define MAX 50

using namespace std;

struct Queue {
    int nilai[MAX];
    int front, rear;
};

Queue queue;  // Declare the queue globally

bool isEmpty() {
    return queue.front == -1;
}

bool isFull() {
    return (queue.rear + 1) % MAX == queue.front;
}

void Enqueue(int x) {
    if (isFull()) {
        cout << "\nQueue penuh" << endl;
    } else {
        if (isEmpty()) {
            queue.front = queue.rear = 0;
        } else {
            queue.rear = (queue.rear + 1) % MAX;
        }
        queue.nilai[queue.rear] = x;
    }
}

void Dequeue() {
    if (isEmpty()) {
        cout << "\nQueue kosong\n" << endl;
    } else {
        if (queue.front == queue.rear) {
            queue.front = queue.rear = -1;
        } else {
            queue.front = (queue.front + 1) % MAX;
        }
    }
}

void Output() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        int valuesToPrint[] = {1, 4, 6};
        int numValuesToPrint = sizeof(valuesToPrint) / sizeof(valuesToPrint[0]);

        for (int i = queue.front; i != (queue.rear + 1) % MAX; i = (i + 1) % MAX) {
            for (int j = 0; j < numValuesToPrint; ++j) {
                if (queue.nilai[i] == valuesToPrint[j]) {
                    cout << queue.nilai[i] << " ";
                    break;  // Move to the next element in the outer loop
                }
            }
        }
    }
}

int main() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(2);
    Enqueue(1);
    Enqueue(4);
    Enqueue(0);
    Enqueue(1);
    Enqueue(4);
    Enqueue(6);

    Output();
    return 0;
}
