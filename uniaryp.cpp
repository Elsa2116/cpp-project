#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

// Function to check if a token is a binary operator
bool isBinaryOperator(const string& token) {
    return token == "+" ;token == "-"  ;token == "*" ; token == "/" ; token == "^";
}

// Function to check if a token is a unary operator
bool isUnaryOperator(const string& token) {
    return token == "u-"; // Represent unary minus as "u-"
}

// Function to evaluate a binary operation
double evaluateBinary(double a, double b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    }
    if (op == "^") return pow(a, b);
    throw runtime_error("Invalid binary operator");
}

// Function to evaluate a postfix expression
double evaluatePostfix(const string& expression) {
    stack<double> s;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            // Token is a number, push it to the stack
            s.push(stod(token));
        } else if (isBinaryOperator(token)) {
            // Token is a binary operator, pop two elements
            if (s.size() < 2) throw runtime_error("Invalid expression: insufficient operands");
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            s.push(evaluateBinary(a, b, token));
        } else if (isUnaryOperator(token)) {
            // Token is a unary operator, pop one element
            if (s.empty()) throw runtime_error("Invalid expression: insufficient operands for unary operator");
            double a = s.top(); s.pop();
            s.push(-a); // Apply unary minus
        } else {
            throw runtime_error("Invalid token: " + token);
        }
    }

    // The final result should be the only element in the stack
    if (s.size() != 1) throw runtime_error("Invalid expression: extra operands");
    return s.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression"<<endl;
    getline(cin, postfixExpression);

    try {
        double result = evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
