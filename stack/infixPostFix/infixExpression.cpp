#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char op) {
    if(op == '*' || op=='/') return 2;
    else return 1;
}

int solve(int val1 ,int val2 ,char op){
    if      (op=='+') return val2+val1;
    else if(op=='-') return val2-val1;
    else if(op=='*') return val2*val1;
    else  return val2/val1;
}

int main() {
    string s="1+3*8/8-3";
    stack<int> val;
    stack<char> op;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            val.push(s[i]-'0');
        }
        else {
            // process operators with higher or equal precedence
            while(!op.empty() && priority(s[i]) <= priority(op.top())) {
                int val1 = val.top(); val.pop();
                int val2 = val.top(); val.pop();
                char ch= op.top();

                // if(op.top() == '+') val.push(val1 + val2);
                // else if(op.top() == '-') val.push(val1 - val2);
                // else if(op.top() == '*') val.push(val1 * val2);
                // else if(op.top() == '/') val.push(val1 / val2);
                val.push(solve(val1,val2,ch));
                op.pop();
            }
            op.push(s[i]);
        }
    }

    // process remaining operators
    while(!op.empty()) {
        int val1 = val.top(); val.pop();
        int val2 = val.top(); val.pop();

        // if(op.top() == '+') val.push(val1 + val2);
        // else if(op.top() == '-') val.push(val1 - val2);
        // else if(op.top() == '*') val.push(val1 * val2);
        // else if(op.top() == '/') val.push(val1 / val2);
        val.push(solve(val1,val2,op.top()));

        op.pop();
    }

    cout << val.top() << endl;
    cout<<1+3*8/8-3;
}
