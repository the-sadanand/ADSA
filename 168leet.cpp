#include<iostream>
#include<string>
using namespace std;

string convertToTitle(int n){
    string result = "";
    while(n>0){
        n--;
        char ch = 'A'+(n%26);
        result=ch+result;
        n/=26;
    }
    
    return result;
    
}
int main(){
cout<<convertToTitle(28);
}