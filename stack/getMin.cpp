#include<iostream>
#include<stack>
using namespace std;

class stackOpreation{
    public:
    stack<int>st;
    stack<int>helper;
    void push(int value){
        st.push(value);
        if( helper.size()==0 || value<helper.top()){
            helper.push(value);
        }
        else helper.push(helper.top());

    }
    void pop(){
            st.pop();
            helper.pop();
    }

    int top(){
        return st.top();
    }

    int getMin(){
        return helper.top();
    }
};
int main(){
    stackOpreation s;
    s.push(23);
    s.push(2);
    s.push(10);
    s.push(11);
    s.push(9);
    s.pop();
    cout<<s.getMin();
}