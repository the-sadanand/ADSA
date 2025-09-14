#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void stockSpan(vector<int>given){
        int size = given.size();
        stack<int>prevGreater;
        stack<int>preIdx;
        preIdx.push(0);
        vector<int>ans(size,-1);  //100,80,60,70,60 ,75,85
        for(int i=1 ;i<size;i++){
            while(preIdx.size()!=0 && given[preIdx.top()]<=given[i]){
                preIdx.pop();
            }
            if(preIdx.size()!=0) ans[i]=preIdx.top();
            preIdx.push(i); 
        }
        cout<<"Printing just previous greater element Index :"<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl<<"Span Time of Stock \n";
        vector<int>span(ans.size());
        for(int i=0;i<ans.size();i++){
                span[i]=i-ans[i];
                cout<<span[i]<<" ";
        }
        return ;
}

int main(){
    vector<int>given{100,80,60,70,60 ,75,85};//-1,0,1,1,3,1,0
                            // span time : 1,1,1,2,1,4,6
    stockSpan(given);
}