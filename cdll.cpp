#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;
public:
    CircularDoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            insertAtBeginning(val);
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 0) insertAtBeginning(val);
        else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
            if (!temp) return; // Position out of bounds
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            if (newNode->next == head) head->prev = newNode; // Update tail
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        if (head->next == head) delete head, head = nullptr; // Single node
        else {
            Node* tail = head->prev;
            tail->next = head->next;
            head->next->prev = tail;
            delete head;
            head = tail->next; // Update head
        }
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) delete head, head = nullptr; // Single node
        else {
            Node* tail = head->prev;
            tail->prev->next = head;
            head->prev = tail->prev;
            delete tail;
        }
    }

    void deleteAtPosition(int pos) {
        if (pos == 0) deleteAtBeginning();
        else {
            Node* temp = head;
            for (int i = 0; temp && i < pos; i++) temp = temp->next;
            if (!temp || temp == head) return; // Position out of bounds
            temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void search(int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == val) {
                cout << "Element " << val << " found." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Element " << val << " not found." << endl;
    }

    void traverseForward() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void traverseBackward() {
        if (!head) return;
        Node* tail = head->prev;
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }

    void menu() {
        int choice, value, position;

        do {
            cout << "\nMain Menu:\n1. Circular Doubly Linked List\n2. Exit\nEnter your choice: ";
            cin >> choice;

            if (choice == 1) {
                do {
                    cout << "\nCircular Doubly Linked List Menu:\n"
                         << "1. Insert at Beginning\n"
                         << "2. Insert at End\n"
                         << "3. Insert at Position\n"
                         << "4. Delete at Beginning\n"
                         << "5. Delete at End\n"
                         << "6. Delete at Position\n"
                         << "7. Search Element\n"
                         << "8. Traverse Forward\n"
                         << "9. Traverse Backward\n"
                         << "10. Back to Main Menu\n"
                         << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: cout << "Enter value: "; cin >> value; insertAtBeginning(value); break;
                        case 2: cout << "Enter value: "; cin >> value; insertAtEnd(value); break;
                        case 3: cout << "Enter value and position: "; cin >> value >> position; insertAtPosition(value, position); break;
                        case 4: deleteAtBeginning(); break;
                        case 5: deleteAtEnd(); break;
                        case 6: cout << "Enter position: "; cin >> position; deleteAtPosition(position); break;
                        case 7: cout << "Enter value to search: "; cin >> value; search(value); break;
                        case 8: traverseForward(); break;
                        case 9: traverseBackward(); break;
                        case 10: break; // Back to Main Menu
                        default: cout << "Invalid choice!\n";
                    }
                } while (choice != 10);
            }
        } while (choice != 2);
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    cdll.menu();
    return 0;
}

