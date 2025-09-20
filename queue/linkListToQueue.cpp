#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next = NULL;
    }
};

class Queue{
public:
    Node* tail;
    Node* head;
    int s;
    Queue(){
        head=tail=NULL;
        s=0;
    }
    void push(int val){
        Node* temp = new Node(val);
        if(s==0) head=tail= temp;
        else{
            tail->next = temp;
            tail=temp;
        }
        s++;
    }

    void pop(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node* temp = head;
        head= head->next;
        delete(temp);
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        } 
        return head->val;       
    }

    int back(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
        }
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size(){
        return s;
    }

    bool empty(){
        if (s==0) return true;
        else return false;
    }

};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(40);
    q.push(60);
    q.push(70);
    q.push(60);
    q.push(00);
    q.push(20);
    q.display();
    cout<<q.size()<<endl;
    q.pop();
    q.display();
    cout<<q.size();
}