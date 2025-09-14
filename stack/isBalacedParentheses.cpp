#include<iostream>
#include<stack>
using namespace std;

bool isValidParantheses(string exp){
    string onlyBracket="";
    // storing only bracket in other string
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='(' || exp[i]==')' || exp[i]=='{' || exp[i]=='}' || exp[i]=='['||exp[i]==']' ){
            onlyBracket+=exp[i];
        }
    }

    stack<char> smallbracket;
    stack<char> curlybracket;
    stack<char> bigbracket;

    for(int i=0;i<onlyBracket.size();i++){
        if(onlyBracket[i]=='(' || onlyBracket[i]==')'){
            if(onlyBracket[i]=='('){
                smallbracket.push('(');
            }
            else {
                smallbracket.pop();
            }
        }
        if(onlyBracket[i]=='{' || onlyBracket[i]=='}'){
            if(onlyBracket[i]=='{'){
                curlybracket.push('{');
            }
            else {
                curlybracket.pop();
            }
        }
        if(onlyBracket[i]=='[' || onlyBracket[i]==']'){
            if(onlyBracket[i]=='['){
                bigbracket.push('[');
            }
            else {
                bigbracket.pop();
            }
        }
    }

    return (smallbracket.size()==0 && curlybracket.size()==0 &&  bigbracket.size()==0 );
}

int main(){
    string s="[[[[(4*5)[{(3+6)}]9]6+9](3+5)]/6]";
    if(isValidParantheses(s)){
        cout<<"Given expression is valid !";
    }
    else {
        cout<<"Given expression is not valid !";
    }
}