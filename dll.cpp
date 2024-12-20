#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List Class
class DoublyLinkedList {
    Node* head = nullptr;

public:
    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, head, nullptr};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int data, int pos) {
        if (pos == 0) { insertAtBeginning(data); return; }
        Node* newNode = new Node{data, nullptr, nullptr};
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp) return; // Position out of bounds
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (pos == 0) { deleteAtBeginning(); return; }
        Node* temp = head;
        for (int i = 0; temp && i < pos; i++) temp = temp->next;
        if (!temp) return; // Position out of bounds
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) {
                cout << "Found: " << data << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found: " << data << endl;
    }

    void traverseForward() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;
    }

    void traverseBackward() {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next; // Go to the last node
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function with menus
int main() {
    DoublyLinkedList dll;
    int choice, data, pos;

    do {
        cout << "\nMain Menu:\n1. Doubly Linked List\n2. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            do {
                cout << "nDoubly Linked List Menu:\n"
                     << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n"
                     << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n"
                     << "7. Search an Element\n8. Traverse Forward\n9. Traverse Backward\n10. Back to Main Menu\nChoose: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter data: ";
                        cin>> data;
                        dll.insertAtBeginning(data);
                         break;
                    case 2:
                         cout << "Enter data: ";
                         cin >> data;
                         dll.insertAtEnd(data);
                         break;
                    case 3:
                         cout << "Enter data and position: ";
                          cin >> data >> pos;
                          dll.insertAtPosition(data, pos);
                          break;
                    case 4:
                        dll.deleteAtBeginning();
                         break;
                       case 6:
                            cout << "Enter position: ";
                            cin >> pos;
                             dll.deleteAtPosition(pos);
                             break;
                       case 7:
                        cout<<"enter data";
                        dll.deleteAtEnd();
                        break;
                    case 8:
                        cout << "Enter element to search: ";
                        cin >> data;
                         dll.search(data);
                         break;
                    case 9:
                        dll.traverseForward();
                        break;
                    case 10:
                        dll.traverseBackward();
                         break;
                    case 11:
                         break; // Back to main menu
                    default:
                         cout << "Invalid choice!\n";
                }
            } while (choice != 10);
        }
    } while (choice != 2);
    return 0;
}


