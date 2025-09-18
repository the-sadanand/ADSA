#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    if (ch == '/' || ch == '*') return 2;
    return 1; // + or -
}

string solve(string left, string right, char op) {
    string s = "";
    s.push_back(op);
    s += left;
    s += right;
    return s;
}

int main() {
    string s = "7+9*4/8-3";
    stack<string> val;
    stack<char> op;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            val.push(string(1, s[i]));
        }
        else if (s[i] == '(') {
            op.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                char ch = op.top(); op.pop();
                string right = val.top(); val.pop();
                string left = val.top(); val.pop();
                val.push(solve(left, right, ch));
            }
            if (!op.empty()) op.pop(); // remove '('
        }
        else { // operator
            while (!op.empty() && op.top() != '(' && priority(s[i]) <= priority(op.top())) {
                char ch = op.top(); op.pop();
                string right = val.top(); val.pop();
                string left = val.top(); val.pop();
                val.push(solve(left, right, ch));
            }
            op.push(s[i]);
        }
    }

    while (!op.empty()) {
        char ch = op.top(); op.pop();
        string right = val.top(); val.pop();
        string left = val.top(); val.pop();
        val.push(solve(left, right, ch));
    }

    cout << val.top() << endl;
    return 0;
}
