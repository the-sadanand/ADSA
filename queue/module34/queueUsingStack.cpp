// LeetCode 232:
// Using tow stack
// We have push tc 1 and pop tc :n 
// else push tc :n and pop tc 1;
// push pop font back

#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
public:
    stack<int> st;
    stack<int> helper;
    MyQueue(){

    }

    void push(int x){ // O(1)
        st.push();
    }

    int pop(){
        // remove at bottom
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;

    }

    int peek(){
        // front
        
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;

    }
    bool empty(){
        if(st.size()==0) return true;
        else return false;
    }

}
int main(){
    MyQueue mQ;
    
    return 0;
}
