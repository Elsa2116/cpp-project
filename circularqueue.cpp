#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    // Constructor to initialize the circular queue
    CircularQueue(int size) {
        arr = new int[size]; // Allocate memory for the queue
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory
    CircularQueue() {
        delete[] arr; // Deallocate memory used for the queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (count == 0);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (count == capacity);
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cerr << "Queue is full. Cannot enqueue " << value << "." << endl;
            return; // Indicate error
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value; // Add new element
        count++; // Increment count
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate error
        }
        int value = arr[front]; // Get the front element
        front = (front + 1) % capacity; // Circular increment
        count--; // Decrement count
        cout << value << " dequeued from the queue." << endl;
        return value; // Return the dequeued value
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot peek." << endl;
            return -1; // Indicate error
        }
        return arr[front]; // Return the front element without removing it
    }

    // Function to get the current size of the queue
    int size() {
        return count;
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Main function to demonstrate the circular queue operations
int main() {
    CircularQueue q(5); // Create a circular queue of capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    q.enqueue(40);
    q.enqueue(50);

    q.display(); // Display current elements in the queue

    q.enqueue(60); // This will show an error since the queue is full

    while (!q.isEmpty()) {
        q.dequeue();
    }

    // Trying to dequeue from an empty queue
    q.dequeue();

    return 0;
}

