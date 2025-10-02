// Priority Queues or Heap
#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;// max heap
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    // min heap
    // lec 2
    priority_queue<int, vector<int> ,greater<int>> mpq;
    mpq.push(-3);
    mpq.push(8);
    cout<<mpq.top();

}