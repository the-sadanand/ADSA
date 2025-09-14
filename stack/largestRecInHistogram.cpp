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
        while(nextSmall.size()!=0 && question[nextSmall.top()]>= question[i]){
        nextSmall.pop();
        }
        if(nextSmall.size()!=0) smallStore[i]=nextSmall.top();
        else smallStore[i]=size;
        nextSmall.push(i);

        // for previous smaller
        while(preSmall.size()!=0 && question[preSmall.top()]>= question[j]){
        preSmall.pop();
        }
        if(preSmall.size()!=0) previousSmall[j]=preSmall.top();
        else previousSmall[j]=-1;
        preSmall.push(j);
        
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
    cout<<endl;
    // area of max reactangle for every index 
    int maxArea=0;
    for(int i=0 ; i<size;i++){
       int area= (smallStore[i]-previousSmall[i]-1)*question[i];
       cout<<area<<" ";
       maxArea= max(maxArea,area);

    }

    // Max area 
    cout<<"\n Maxium area in given historgram of a rectangle is : "<<maxArea;

    return ;
}

int main(){
    vector<int> questions{2,1,5,6,2,3};
    nextSmaller(questions);
}
