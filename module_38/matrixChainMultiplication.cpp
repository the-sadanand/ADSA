// matrix chain multiplication 
/* hey in this program a vector of int is given , and a pair which is cosider as dimension of the matrix that is a[i-1] and a[i] , from n-1 pair of martrix return the minum number of mutiplication to get all the made matrix multiplication
like abcd => ab(cd),(ab)(cd) etc */

#include<vector>
#include<iostream>
#include <climits>
using namespace std;
vector<vector<int>> dp;
// considerin i to j element of arr 
int f(int i , int j , vector<int>&arr){
    if(i==j || j==i+1) return 0; // when [a,b] shows dim of matrix and its mul is zero 
    // cuz it is single matrix
    /*
    what i am implementing in using this loop and k variable is 
    if element is from i to j , then i+1 <= k <=j-1
     where k form the different seperatio in one call two sepation of whole given array from i to k and k to j    */
    int ans = INT_MAX;

    for(int k = i+1 ; k<=j-1 ; k++){
        ans = min(ans, f(i,k,arr)+f(k,j,arr)+arr[i]*arr[j]*arr[k]);
    }
    return ans;

}


int main(){
    vector<int> arr = {4,2,3,1,3};
    cout<<f(0, arr.size()-1, arr);
}