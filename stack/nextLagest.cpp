#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextLargest(vector<int> givenCollection){
    int size = givenCollection.size();
    stack<int> nextBigger;
    vector<int> LargerStorage(size, -1);

    for(int i = size - 1; i >= 0; i--){
        while(!nextBigger.empty() && nextBigger.top() <= givenCollection[i]){
            nextBigger.pop();
        }
        if(!nextBigger.empty()){
            LargerStorage[i] = nextBigger.top();
        }
        nextBigger.push(givenCollection[i]);
    }

    return LargerStorage;
}

int main(){
    vector<int> givenCollection = {2, 4, 8, 10, 3, 1, 6};
    vector<int> ans = nextLargest(givenCollection);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;

}