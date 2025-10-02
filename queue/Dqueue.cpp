#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* pre;
    Node(int val){
        this->val=val;
        this->next = NULL;
        this->pre = NULL;
    }
};

class Dqueue{
public:
    Node* tail;
    Node* head;
    int s;
    Dqueue(){
        head=tail=NULL;
        s=0;
    }
    void push_back(int val){
        Node* temp = new Node(val);
        if(s==0) head = tail = temp;
        else{
            tail->next = temp;
            temp->pre=tail;
            tail=temp;
        }
        s++;
    }
    void push_front(int val){
        Node* temp = new Node(val);
        if(s==0) head = tail = temp;
        else{
            temp->next = head;
            head->pre= temp;
            head = temp;
        }
        s++;
    }

    void pop_front(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node* temp = head;
        head= head->next;
        if(head)head->pre = NULL;
        if(head==NULL) tail=NULL;
        delete(temp);
        s--;
    }
    void pop_back(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        else if(s==1){
            pop_front();
            return;
        }
        Node* temp = tail;
        tail = tail->pre;
        tail->next = NULL;
        delete temp;
        s--;
    }

    int get_front(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        } 
        return head->val;       
    }

    int get_back(){
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
    Dqueue dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(40);
    dq.push_front(60);
    dq.push_front(70);
    dq.push_front(60);
    dq.push_front(00);
    dq.push_front(20);
    dq.display();
    cout<<dq.size()<<endl;
    dq.push_back(34);
    dq.pop_front();
    dq.display();
    dq.pop_back();
    cout<<dq.size()<<endl;
    cout<<dq.get_front();
}