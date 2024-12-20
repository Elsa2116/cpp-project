#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // Helper function for deletion
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->data = temp->data; // Copy the inorder successor's content to this node
            node->right = deleteNode(node->right, temp->data); // Delete the inorder successor
        }
        return node;
    }

    // Helper function to find the minimum value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to find the maximum value node
    Node* maxValueNode(Node* node) {
        Node* current = node;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder traversal
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Public insert function
    void insert(int key) {
        root = insert(root, key);
    }

    // Public delete function
    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    // Function to find the minimum value in the BST
    int findMin() {
        Node* minNode = minValueNode(root);
        return minNode ? minNode->data : -1; // Return -1 if tree is empty
    }

    // Function to find the maximum value in the BST
    int findMax() {
        Node* maxNode = maxValueNode(root);
        return maxNode ? maxNode->data : -1; // Return -1 if tree is empty
    }

    // Wrapper for preorder traversal
    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Wrapper for postorder traversal
    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

// Example usage
int main() {
    BinarySearchTree bst;

    // Inserting elements into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display traversals
    bst.preorder();
    bst.postorder();

    // Finding minimum and maximum values
    cout << "Minimum value in the BST: " << bst.findMin() << endl;
    cout << "Maximum value in the BST: " << bst.findMax() << endl;

    // Deleting a key from the BST
    bst.deleteKey(20);  // Deleting a leaf node
    cout << "After deleting 20:" << endl;
    bst.preorder();

    bst.deleteKey(30);  // Deleting a node with one child
    cout << "After deleting 30:" << endl;
    bst.preorder();

    bst.deleteKey(50);  // Deleting a node with two children
    cout << "After deleting 50:" << endl;
    bst.preorder();

    return 0;
}

