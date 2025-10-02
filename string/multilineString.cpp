#include<iostream>
using namespace std;
int main(){
    // First method
    string text = "This is line one.\n"
    "This is line Two.\n"
    "This is line Three";
    cout<<text<<endl;
    // second method
    string Rmethod= R"("This is using R ( ....) 
        I am printing multiline string in cpp )";
    cout<<Rmethod<<endl;

    // third method
    
    string useAdd = "this is one line and another \n";
    useAdd+="Another line added \n";
    useAdd+="Let Add third Line";
    cout<<useAdd;

}