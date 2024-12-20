#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;

    // Add elements to the front and back
    dq.push_front(10);  // Add 10 to the front
    dq.push_back(20);   // Add 20 to the back
    dq.push_front(5);   // Add 5 to the front
    dq.push_back(25);   // Add 25 to the back

    // Display the contents of the deque
    cout << "Deque contents: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    // Remove elements from the front and back
    dq.pop_front();  // Remove element from the front
    dq.pop_back();   // Remove element from the back

    // Display the contents of the deque after removals
    cout << "Deque after popping: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
