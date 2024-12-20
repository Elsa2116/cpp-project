#include <iostream>
using namespace std;

// Array-based Stack
class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(int data) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
        cout << data << " pushed to stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

// Node structure for Linked List Stack
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack() {
        while (top) {
            pop();
        }
    }

    void push(int data) {
        Node* newNode = new Node{data, top};
        top = newNode;
        cout << data << " pushed to stack." << endl;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack." << endl;
        delete temp;
    }

    void peek() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    int choice, stackType, size, data;

    do {
        cout << "\nMain Menu:\n"
             << "1. Array-Based Stack\n"
             << "2. Linked List-Based Stack\n"
             << "3. Exit\n"
             << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Array-Based Stack
                cout << "Enter size of the stack: ";
                cin >> size;
                ArrayStack arrayStack(size);
                do {
                    cout << "\nArray Stack Menu:\n"
                         << "1. Push\n"
                         << "2. Pop\n"
                         << "3. Peek\n"
                         << "4. Check if Empty\n"
                         << "5. Check if Full\n"
                         << "6. Back to Main Menu\n"
                         << "Choose an option: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter data: ";
                            cin >> data;
                            arrayStack.push(data);
                            break;
                        case 2:
                            arrayStack.pop();
                            break;
                        case 3:
                            arrayStack.peek();
                            break;
                        case 4:
                            cout << (arrayStack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                            break;
                        case 5:
                            cout << (arrayStack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                            break;
                        case 6:
                            break; // Back to main menu
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                } while (choice != 6);
                break; // End of Array-Based Stack

            }
            case 2: { // Linked List-Based Stack
                LinkedListStack linkedListStack;
                do {
                    cout << "\nLinked List Stack Menu:\n"
                         << "1. Push\n"
                         << "2. Pop\n"
                         << "3. Peek\n"
                         << "4. Check if Empty\n"
                         << "5. Back to Main Menu\n"
                         << "Choose an option: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter data: ";
                            cin >> data;
                            linkedListStack.push(data);
                            break;
                        case 2:
                            linkedListStack.pop();
                            break;
                        case 3:
                            linkedListStack.peek();
                            break;
                        case 4:
                            cout << (linkedListStack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                            break;
                        case 5:
                            break; // Back to main menu
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                } while (choice != 5);
                break; // End of Linked List-Based Stack

            }
            case 3:
                cout << "Exiting..." << endl;
                break; // Exit
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}


