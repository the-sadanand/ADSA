#include<iostream>
#include<stack>
using namespace std;

stack<int> Reverse(stack<int>originalStack){
    int n = originalStack.size();
    stack<int>firstHelper;
    stack<int>secondtHelper;
    for(int i=0;i<n;i++){
        int ele=originalStack.top();
        firstHelper.push(ele);
        originalStack.pop();
    }
    
    for(int i=0;i<n;i++){
    int ele=firstHelper.top();
    secondtHelper.push(ele);
    firstHelper.pop();
   }

   for(int i=0;i<n;i++){
    int ele=secondtHelper.top();
    originalStack.push(ele);
    secondtHelper.pop();
  }
    
  return originalStack;   
}

int main(){
stack<int> st;
st.push(20);
st.push(30);
st.push(50);
st.push(89);
st.push(21);
st.push(29);
st.push(40);
st.push(22);
st.push(29);
Reverse(st);
// Print reverse stack
int size = st.size();
for(int i=0;i<size;i++){
    cout<<st.top()<<" ";
    st.pop();
}
  

}