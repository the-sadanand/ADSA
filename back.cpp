#include<iostream>
#include<vector>
using namespace std;
vector<char>all;
void allCombo(int size){
    if(all.size()==size){
        for(int i=0 ; i<all.size();i++){
            cout<<all[i];
        }
        cout<<endl;
        return;
    }

    all.push_back('0');
    allCombo(size);
    all.pop_back();
    all.push_back('1');
    allCombo(size);
    all.pop_back();

}

int main(){
    allCombo(3);
}