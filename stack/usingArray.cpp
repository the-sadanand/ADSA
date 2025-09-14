#include<iostream>
using namespace std;
class Stack{
private:
    int* arr; // Pointer to array that holds stack elements
    int top; // Index of top elements
    int capacity ; // Maximum size of the stack
public:
    // Constructor to initialize the stack
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1; // stack is initally empty
    }

    // Destructor to free memory
    ~Stack(){
        delete[] arr;
    }
    // Push an element to the top of the stack
    void push(int value){
        if(isFull()){
            cout<<"Stack Overflow ! can't push more"<<value<<endl;
            return ;
        }
        arr[++top]=value;
        cout<<"pushed  "<<value<<"to the stack"<<endl;
    }
    // Remove and return the top element
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        cout<<"Popped "<<arr[top]<<" from the stack"<<endl;
        return arr[top--];
    }
    // Return the top element without removing it

    int peek(){
        if(isEmpty()) {
            cout<<"stack is empty"<<endl;
        }
        return arr[top];
    }
    // check is stack is full or not
    bool isFull(){
        return top==capacity-1;
    }
    // check is stack is empty
    bool isEmpty(){
        return top== -1;
    }
    // return the size of stack
    int size(){
        return top+1;
    }
    // display all the elements of the stack 
    void display(){
        if(isEmpty()){
            cout<<"stack is empty!"<<endl;
            return;
        }
        for(int i =top ;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    // Create a stack with capcity of s
    Stack myStack(5);
    // Demonstrate stack operations
    cout<<"Stack using Array"<<endl;
    cout<<"is stack Empty "<<(myStack.isEmpty()?"Yes":"No")<<endl;
    // push elements
    myStack.push(10);
    myStack.push(0);
    myStack.push(1);
    myStack.push(34);
    myStack.push(5);
    // full
    myStack.push(1);
    cout<<"is stack Empty "<<(myStack.isEmpty()?"Yes":"No")<<endl;
    cout<<" stack is " <<endl;
    myStack.display();
    cout<<"Top element of the stack"<< myStack.peek()<<endl;

    // delete 
    myStack.pop();
    myStack.pop();

    cout<< "size of the stack" <<myStack.size();
    cout<<" stack is " <<endl;
    myStack.display();

    return 0;
}