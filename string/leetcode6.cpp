#include<iostream>
#include<string>
#include<vector>
using namespace std;
void zigZag(string s , int k){
    // from 0 to k -1 down words 
    // then from k-1 to 0 upward 
    if (k == 1) {
        cout << s << endl;
        return;
    }
    vector<string> v(k);
    int level = 0;
    int direction = 1; // 1: down, -1: up
    for (int i = 0; i < s.length(); i++) {
        v[level] += s[i];
        if (level == 0)
            direction = 1;
        else if (level == k - 1)
            direction = -1;
        level += direction;
    }
    for (int i = 0; i < k; i++) {
        cout << v[i]<<" ";
    }
    cout << endl;
    string finalAns="";
    for(int i = 0 ; i<k ; i++){
        finalAns+=v[i];
    }
    cout<<finalAns<<endl;


}
int main(){
string s ="PAYPALISHIRING";
zigZag(s, 3);
}