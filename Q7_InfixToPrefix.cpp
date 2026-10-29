#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, rev, prefix;
    stack<char> st;
    cout << "Enter infix expression (single-letter/digit operands): ";
    cin >> infix;
    rev = infix;
    reverse(rev.begin(), rev.end());
    for (char &c : rev) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string post;
    for (char c : rev) {
        if (isalnum(static_cast<unsigned char>(c))) post += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top(); st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' &&
                (precedence(st.top()) > precedence(c) ||
                (precedence(st.top()) == precedence(c) && c == '^'))) {
                post += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { post += st.top(); st.pop(); }
    prefix = post;
    reverse(prefix.begin(), prefix.end());
    cout << "Prefix: " << prefix << "\n";
    return 0;
}
