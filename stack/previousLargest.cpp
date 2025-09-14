#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void previousLargest(vector<int>given){
        int size = given.size();
        stack<int>prevGreater;
        vector<int>ans(size);
        for(int i=0 ;i<size;i++){
            while(prevGreater.size()!=0 && prevGreater.top()<=given[i]){
                prevGreater.pop();
            }
            if(prevGreater.size()!=0) ans[i]=prevGreater.top();
            else ans[i]=-1;
            prevGreater.push(given[i]);  
        }

        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        return ;
}

int main(){
    vector<int>given{3,8,6,12,10,11};
    previousLargest(given);
}