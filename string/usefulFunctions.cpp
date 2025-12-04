#include<bits/stdc++.h>
using namespace std;
int main(){
    string s= "Hello World";
    cout<<"Original stirng:"<<s<<"\n";

    cout<<"length: "<<s.length()<<"\n\n";
    string s2 = "!!!";
    cout<<"Append: "<<s.append(s2)<<"\n";
    cout<<"using + : "<<(s+ "c++") << "\n\n";
    // Reset stirng
    s = "hello world";
    cout<<"Substring(pos =6 , len = 5 ): "<<s.substr(6,5)<<"\n\n";

    size_t pos=s.find("world");
    if(pos != stirng::npos)
}