#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "hello";
    cout<<s1<<endl;
    string s2 ;
    cin>>s2; // read a single word
    cout<<s2<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string s3;
    getline(cin, s3);
    cout<<s3<<endl;
    string name ;
    getline(cin,name);
}