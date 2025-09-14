#include<iostream>
#include<stack>

using namespace std;

void ReversOfString(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }

    // printing the stack
    for(int i=0;i<s.size();i++){
        cout<<st.top();
        st.pop();
    }

}

int main(){
    string s="sdf485t8flskq47585 4959fjgj";
    cout<<s.size()<<endl;
    ReversOfString(s);
}