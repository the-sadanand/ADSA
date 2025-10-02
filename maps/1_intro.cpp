// fre
// key (value / index)
// insertion , serching and deletions in tc O(1)

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    pair<int, string> p1, p2, p3;// built in
    p1.first=1;
    p1.second="sadanand" ;
    cout<<"Roll NO " <<p1.first<<": "<<p1.second<<endl;
    unordered_map<int, string> m;// maps takes pair
    // m.insert("sadaad",1); not work

    p2.first=2;
    p2.second="anand" ;
    p3.first=1;
    p3.second="sad" ;    
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    // another way to insert
    m[5]="raushan";
    // in place of auto if i want to use pair 
    // then syntax is : pari<data_types, data_types>
    cout<<m.size()<<endl;
    // for delet
    m.erase(5);
    cout<<m.size()<<endl;
    cout<<m[1]<<endl;

    for(/*auto or */  pair<int, string> p : m ){
        cout<<"Roll NO " <<p.first<<": "<<p.second<<endl;
    }
    
    return 0; 
}