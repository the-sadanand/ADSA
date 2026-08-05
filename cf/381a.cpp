#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cards[n];
    for(int i = 0 ; i<n ; i++){
        cin>>cards[i];
    }
    bool turn = 1 ;
    int i= 0 , j = n-1;
    int serja_score = 0 , dima_socre = 0;
    while(i<=j){
        if(turn){
            if(cards[i]>cards[j]){
                serja_score+=cards[i];
                i++;
            }
            else {
                serja_score+=cards[j];
                j--;
            }
            turn = 0;
        }
        else {
            if(cards[i]>cards[j]){
                dima_socre+=cards[i];
                i++;
            }
            else{
                dima_socre+=cards[j];
                j--;
            }
            turn = 1;
        }
    }
    cout<<serja_score<<" "<<dima_socre<<endl;
}