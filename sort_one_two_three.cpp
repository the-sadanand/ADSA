#include<iostream>
#include<vector>
using namespace std;
vector<int> sort_one_tow_three(vector<int> &v ){
    int mid = 0 , left =0 , right = v.size()-1;
    while(mid<=right){
        if(v[mid]==0){
            swap(v[left],v[mid]);
            left++;
            mid++;
        }
        else if(v[mid]==2){
            swap(v[mid],v[right]);
            right--;
        }
        else{ 
            mid++;
        }
    }
  return v;
   
}

int main()
{
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>> n;
    cout<<"Enter only 0,1,2 "<<endl;
    vector<int> v(n);
    for(int i = 0 ; i< n ; i++){
        int x;
        cin>>x;
        v[i]=x;

    }
    v = sort_one_tow_three(v);
    for(int i = 0 ; i<n ;i++){
        cout<<v[i]<<" ";
    }
}
