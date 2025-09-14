#include<iostream>
#include<stack>
using namespace std;


// here math are being used for where we do fake calculation to check min 

// t.c = o(1) , s.c = o(1)

// here we keep a min variable that simply store min xue

// st.push(x+(x-min))    2*min - oldMin

// minimum me se bada minus kareke minimum add kar do as result xue kam hi hoga
// st.top= 2*min-oldmin => oldmin= 2*min-st.top; => min= oldmin

class stackOpreation{
    public:
    stack<long long> st;
    long long min;
    stackOpreation(){// constructor
        min=LLONG_MAX;
    }

    void push(int val){
        long long x = (long long) val;
        if(st.size()==0){
            st.push(x);
            min=x;
        }
        else if(x>=min) st.push(x);
        else {  // x<min
            st.push(2*x-min);
            min=x;

        }
    }

    void pop(){ // o(1)
        if(st.top()<min){ // A fake value is present
            // before popping make sure to retrieve the old min
            long long oldMin = 2* min-st.top();
            min= oldMin;
        }
        st.pop();
    }

    int top(){ // o(1)
        if(st.top()<min) return (int)min;
        else return st.top();
    }

    int getMin(){
        return (int)min;
    }
};

int main(){
    stackOpreation st;
    st.push(34);
    st.push(3);
    st.push(13);
    st.push(33);
    st.push(0);
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
}