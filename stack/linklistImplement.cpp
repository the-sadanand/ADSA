#include<iostream>
using namespace std;
// sturcture for linked list
struct Node
{
    int value;
    Node* next;
    Node( int data){
        value= data;
        next = nullptr;
    }
};

class Stack{
    private:
         Node* top; // pointer to the top of the stack
    public:
        // constructor to initialize empty stack
        Stack(){
            top = nullptr;
        }

        // Destructor to free all allocated memory
        ~Stack(){
            while(!isEmpty()){
                pop();
            }
        }
        // push
        void push(int value){
            Node* newNode = new Node(value);
            newNode->next= top; //New node points to current top
            top=newNode; // update top to new node
            cout<<"Pushed "<<value<<" to the stack"<<endl;
        }
        // pop
        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            Node* temp = top;
            int poppedValue = top->value;
            top=top->next;
            delete temp;
            cout<<"Popped "<<poppedValue<<" from the stack "<<endl;
        }

        int peek(){
            if(isEmpty()){
                cout<<"Stack is empty" << endl;
                return -1;
            }
            return top->value;
        }

        void display(){
            if(isEmpty()) {
                cout<<"Stack is empty "<<endl;
                return;
            }
            cout<<"Stack element top to bottom"<<endl;
            Node *current = top;
            while(current!=nullptr){
                cout<<current->value<<" ";
                current=current->next;
            }
            cout<<endl;
        }

        int size(){
            int count=0;
            Node* current = top;
            while(current!=nullptr){
                count++;
                current=current->next;
            }
            return count;
        }

        bool isEmpty(){
            // if(top==nullptr){
            //     return false;
            // }
            // else  return true;
            return top==nullptr;
        }
};

int main(){
    Stack mystack;
    mystack.push(19);
    mystack.push(10);
    mystack.push(78);
    mystack.display();
    cout<< mystack.size()<<endl;
}