#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(int decimal) {
    stack<int> binaryStack;


    while (decimal > 0) {
        int remainder = decimal % 2;
        binaryStack.push(remainder);
        decimal /= 2;
    }

    cout << "Binary representation: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout <<endl;
}

int main() {
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal < 0) {
        cout << "Please enter a non-negative integer." <<endl;
    } else {
        decimalToBinary(decimal);
    }

    return 0;
}
