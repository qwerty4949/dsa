#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, postfix;
    stack<char> st;
    cout << "Enter infix expression (single-letter/digit operands): ";
    cin >> infix;
    for (char c : infix) {
        if (isalnum(static_cast<unsigned char>(c))) postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top(); st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' &&
                (precedence(st.top()) > precedence(c) ||
                (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { postfix += st.top(); st.pop(); }
    cout << "Postfix: " << postfix << "\n";
    return 0;
}
