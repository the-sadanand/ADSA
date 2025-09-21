// No of students unable to launch

// medium
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    int helper(vector<int>& students, vector<int>& sandwiches){
        queue<int> st;
        queue<int> sd;
        for(int i = 0 ; i<students.size() ; i++ ){
            st.push(students[i]);
            sd.push(sandwiches[i]);
        }
        int count=0;
        while(!st.empty()&&count<st.size()){
            if(st.front()==sd.front()){
                st.pop();
                sd.pop();
                count=0;
            }
            else{
                int eQ = st.front();
                st.push(eQ);
                st.pop();
                count++;
            }
        }
        return sd.size();
    }

int main(){

    vector<int> st ={1,1,0,0};
    vector<int> sd ={0,1,0,1};
   cout<< helper(st,sd);

}