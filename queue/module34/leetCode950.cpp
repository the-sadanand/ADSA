#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
// REveal the card in Increasing Order
using namespace std;

void revealCard(vector<int> &card){
    int n = card.size();
    sort(card.begin(),card.end());
    queue<int> indexFilp; // check index to insert or leave the space 
    // insert leave one space the insert on next space
    vector<int> ans(n); // final vector 

    for(int i =0 ; i < n  ; i++){
        indexFilp.push(i);
    }

    // here is work on problem 
    for(int i =0 ; i < n ; i++){
        int idx= indexFilp.front();
        indexFilp.pop();
        indexFilp.push(indexFilp.front());
        indexFilp.pop();
        ans[idx]=card[i];
    }
    for(int i = 0 ; i <ans.size() ; i++){
    cout<<ans[i]<<" ";
   }
} 
int main(){
    vector<int> card={1,2,3,4,2,4};
    revealCard(card);   
}