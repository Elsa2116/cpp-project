#include <iostream>
#include<stack>
using namespace std;
bool isPalindrome(string& str) {
    stack<char> charStack;

    for (char ch : str) {
        if (isalnum(ch)) {
            charStack.push(tolower(ch));
        }
    }
    for (char ch : str) {
        if (isalnum(ch)) {
            if (charStack.empty() || charStack.top() != tolower(ch)) {
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    string n;
    cout << "Enter a string: ";
getline(cin,n);
    if (isPalindrome(n)) {
        cout <<" it is a palindrome." <<endl;
    } else {
        cout <<"it is not a palindrome." <<endl;
    }

    return 0;
}


