#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
        }
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != head) temp = temp->next;
            delete temp->next;
            temp->next = head;
        }
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

    void menu() {
        int choice, value;

        do {
            cout << "\nCircular Linked List Menu:\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Delete at Beginning\n";
            cout << "4. Delete at End\n";
            cout << "5. Traverse Forward\n";
            cout << "6. Search Element\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                     cout << "Enter value: ";
                cin >> value; insertAtBeginning(value);
                break;
                case 2:
                     cout << "Enter value: ";
                cin >> value; insertAtEnd(value);
                 break;
                case 3:
                     deleteAtBeginning();
                 break;
                case 4:
                    deleteAtEnd();
                break;
                case 5:
                    traverseForward();
                break;
                case 6:
                    cout << "Enter value to search: ";
                 cin >> value; search(value);
                  break;
                case 7:
                     cout << "Exiting...\n";
                 break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 7);
    }
};

int main() {
    CircularLinkedList cll;
    cll.menu();
    return 0;
}

