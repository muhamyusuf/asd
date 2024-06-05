#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum queue size

struct Queue {
    int queueArray[MAX_SIZE];
    int front, rear;

    Queue() {
        createEmpty();
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void createEmpty() {
        front = -1;
        rear = -1;
    }

    void add(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more elements." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queueArray[rear] = value;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return;
        }

        if (front == rear) {
            createEmpty();
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements:" << endl;

        int i = front;
        while (i != rear) {
            cout << queueArray[i] << " -> index " << i << endl;
            i = (i + 1) % MAX_SIZE;
        }

        cout << queueArray[rear] << " -> index " << rear << endl;
        cout << endl;
    }

    int countNode() {
        if (isEmpty()) {
            return 0;
        }

        if (front <= rear) {
            return rear - front + 1;
        } else {
            return MAX_SIZE - front + rear + 1;
        }
    }
};

int main() {
    int size, numFromUser;

    Queue queue;

    cout << "Enter the number of elements to add to the queue: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Number of elements exceeds the maximum capacity." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> numFromUser;

        queue.add(numFromUser);
    }

    cout << "Front element: " << queue.queueArray[queue.front] << endl;

    queue.printQueue();

    cout << "Number of nodes in the queue: " << queue.countNode() << endl;

    return 0;
}
