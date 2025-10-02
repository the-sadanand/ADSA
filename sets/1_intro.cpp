// talk about complexity
// insert , search and delete at O(1)

// sets is not a linear data structure

// operations
/*
insert(), 
size(),
find(), 
begin(),
end(),
erase()*/

// assume sets like a bag containing its element at random place
// its store  unique element

// code

#include<iostream>
#include<unordered_set>
// #include<set>

using namespace std;
int main(){
    // talking about unordered_set
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);// duplicate , but set will not store it
    s.insert(5);
    // its store in random order
    // ? how to print it if its is in random oreder

    // ans:- we are going to use for each loop
    cout<<s.size()<<endl;
    for(int ele : s){
        cout<<ele<<" ";
        // its dosen't contain duplicate 
    }
    s.erase(5);
     for(int ele : s){
     cout<<ele<<" ";
     }// can you see it print 5 only one time

    // what happen it I delet ele that isn' t exists
    
    s.erase(66);

    int target = 4 ;
    // s.find() -> it searches in the set , and if it is not found then return is last element
    // 
    if(s.find(target)!=s.end()){
        // target exits 
        cout<<"exists"<<endl;
    }
    else cout<<"does not exist"<<endl;
}