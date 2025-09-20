#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    // push,front , size , empty , pop, back
    queue<int> q;
    q.push(34);
    q.push(4);
    q.push(14);
    q.push(324);
    q.push(36);
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    // cout<<q.pop(); doesn't return a value
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    // q.back(45);
    cout<<q.back()<<endl; // its print what is in rear side of queue 

    // another queue to learn how to display it and save as it
    // t.c = 1 and s.c = 1 
    cout<<" display the queue and keep it same "<<endl;
    queue<int>display;
    display.push(12);
    display.push(13);
    display.push(14);
    display.push(15);
    display.push(16);
    int size= display.size();
    for(int i =0 ;i<size ;i++){
        cout<<display.front()<<" ";
         display.push(display.front());
        display.pop();  
    }
    cout<<endl;
    cout<<display.size()<<endl;
// Reversing a queue using stack
// it hard to do with another queue 
// but we can take another options in place of using stack

// helper stack
stack<int> helper;
while(!display.empty()){
    helper.push(display.front());
    display.pop();
}
cout<<"size of queue ";
cout<<display.size()<<endl;
cout<<"Now get the reverse queue ......"<<endl;
while(!helper.empty()){
    display.push(helper.top());
    helper.pop();
}
cout<<"Printing Reverse Queue"<<" ";
while(!display.empty()){
    cout<<display.front()<<" ";
    display.pop();
}

// try these thing using function Ok
}