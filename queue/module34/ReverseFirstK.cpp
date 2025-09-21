#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
queue<int> ReversFirstK(queue<int>&q,int k){
    stack<int> storek;
    int sizeQ = q.size();
    for(int i =0 ; i<k ; i++){
        int eQ = q.front();
        q.pop();
        storek.push(eQ);
    }
    while(!storek.empty()){
        q.push(storek.top());
        storek.pop();
    }

    for(int i=0 ; i < sizeQ-k ; i++){
        int eQ = q.front();
        q.pop();
        q.push(eQ);
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    queue<int> ans;
    ans = ReversFirstK(q,10);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

}