#include<iostream>
#include<stack>
using namespace std;
class stak{
public:
    stack <int>st;
    int pus(int value){
        st.push(value);
        cout<<" value " <<value<<" Pushed";
        return 0;
    }
};

int main(){
    // stack<int> st;
    // st.push(20);
    // if(st.top()) cout<<"Element pushed ";
    stak st;
    st.pus(34);
}