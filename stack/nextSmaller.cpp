#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmaller(vector<int>question){
    int size= question.size();
    stack<int>nextSmall;
    stack<int>preSmall;
    vector<int>previousSmall(size);
    vector<int>smallStore(size);
    for(int i=size-1 , j=0 ; i>=0 ,j<=size-1 ; i-- , j++){
        // for next Smaller
        while(nextSmall.size()!=0 && nextSmall.top()>= question[i]){
        nextSmall.pop();
        }
        if(nextSmall.size()!=0) smallStore[i]=nextSmall.top();
        else smallStore[i]=-1;
        nextSmall.push(question[i]);

        // for previous smaller
        while(preSmall.size()!=0 && preSmall.top()>= question[j]){
        preSmall.pop();
        }
        if(preSmall.size()!=0) previousSmall[j]=preSmall.top();
        else previousSmall[j]=-1;
        preSmall.push(question[j]);
        
    }

    // printing next smaller
    for(int i=0; i<size; i++){
        cout<<smallStore[i]<<" ";
    }
    cout<<endl;

    // printing previous smaller
    for(int j=0; j<size; j++){
        cout<<previousSmall[j]<<" ";
    }
    return ;
}

int main(){
    vector<int> questions{2,1,5,6,2,3};
    nextSmaller(questions);
}
