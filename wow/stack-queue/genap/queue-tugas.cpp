#include <iostream>
#include <cctype> // for character type checking
using namespace std;

const int MAX_SIZE = 100; // Maximum queue size

struct Queue {
    int queueArray[MAX_SIZE];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more elements." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queueArray[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return -1;
        }

        int dequeuedValue = queueArray[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        return dequeuedValue;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents:" << endl;

        int i = front;
        while (i != rear) {
            cout << queueArray[i] << " -> index " << i << " (" << char(queueArray[i]) << ")" << endl;
            i = (i + 1) % MAX_SIZE;
        }
        cout << queueArray[rear] << " -> index " << i << " (" << char(queueArray[rear]) << ")" << endl;
    }
};

int main() {
    string input;
    Queue queue;

    cout << "Enter a string: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (islower(c)) {
            queue.enqueue(int(c));
            cout << "ENQUEUE: " << int(c) << " (" << c << ")" << endl;
        } else if (c == '-') {
            int dequeuedValue = queue.dequeue();

            if (dequeuedValue != -1) {
                cout << "DEQUEUE: " << dequeuedValue << " (" << char(dequeuedValue) << ")" << endl;
            }
        }
    }

    queue.printQueue(); // Display remaining characters in the queue
    return 0;
}
