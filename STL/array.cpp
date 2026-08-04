#include<iostream>
#include<array>
using namespace std;

int main(){
    array<int,5> arr = {4,5,6,6,4};
    auto it = arr.begin();
    cout<<(it)<<endl;
    cout<<*it<<endl;
    for(it=arr.begin(); it!=arr.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<arr.size();
    cout<<endl;
    cout<<arr.at(0);
    cout<<endl;
    cout<<arr.at(1);

    cout<<endl;
    for(auto i = arr.rbegin(); i!=arr.rend() ; i++){
        cout<<*i<<" " ; 
    }
    cout<<endl;
    array<int,6> arr1 = {2,3,4,5,6,5};
    array<int,6> arr2 = {4,5,6,36,4,6};
    arr1.swap(arr2);
    cout<<arr1.at(0);
    cout<<arr1.at(10);
}