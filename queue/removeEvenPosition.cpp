#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue <int> RemoveEvenPos(queue<int> &q){
    bool even = true;
    int startingSize = q.size();

    while(startingSize>0){
        if(even){
            q.pop();
            even= false;
        }
        else{
            q.push(q.front());
            q.pop();
            even=true;
        }
        startingSize--;
    }
}

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int> q ;
    int n;
    cout<<"Enter size of queue ";
    cin>>n;
    cout<<"Enter the queue Element "<<endl;
    for(int i=0 ; i<n ; i++){
        int a;
        cin>>a;
        q.push(a);
    }
    display(q);
    cout<<"\nSize of Queue : "<<q.size()<<endl;
    RemoveEvenPos(q);
    cout<<endl;
    display(q);

}