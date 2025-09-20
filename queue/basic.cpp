#include<iostream>
#include<queue>
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
}