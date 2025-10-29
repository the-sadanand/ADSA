#include<iostream>
#include<vector>
using namespace std;

// 0 / 1 Knapsack problem 
class Solutions{
public:
int Knapsack(int cp, vector<int>wt , vector<int> value , int n){

}
};

// print only even positon element 
void printEven(vector<int> &arr,int i){
    if(i==arr.size()) {
        cout<<endl;
        return ;
    }
    if(i%2==0) cout<<arr[i]<<" ";
    printEven(arr,i+1);
    if(i%2!=0) cout<<arr[i]<<" ";
}
void callNo(int i , int n ){
    if(i==n) {
        cout<<endl;
        return ;
    }
    cout<<i<<" ";
    callNo(i+1,n);
    // cout<<i<<" ";

    cout<<"return marr"<<" ";
}

// recursion ko imagine karte hai 

// phale har call call stack me jayega phir durser call stack se phale to kamm ayega phir oo karega 
//phir dursra call , call stack me jayega , phale call ki thara oo kamm karega 
// aise karte karte base hit hone tak call stak me call jayega , jab return hi hoga
// jab call call stack je pop honge aur bacha kaam karte hue honge 
// jab tak call stack khali na ho jaye


void recursionInLoop(int limit , int n){
    if(n==limit) {
        cout<<"return ho ek i value ke liye";
        cout<<endl;
        return ;
    }
    for(int i=1 ; i<=n ; i++){
        cout<<i<<" ";
        recursionInLoop(limit+1,n);
    }
}
int main(){
    vector<int> v ={0,1,2,3,4,5,6,7,8};
    // printEven(v,0);
    // callNo(0,9);
    recursionInLoop(1,2);
}