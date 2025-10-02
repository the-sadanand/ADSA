#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution{
public:
    int reverse(int n){
        int r =0;
        while(n>0){
            r*=10;
            r+=(n%10);
            n/=10;
        }
        return r;
    }
    int CountDistinctIntegers(vector<int> & nums){
        int n= nums.size();
        for(int i =0 ; i < n ; i++){
            int rev = reverse(nums[i]);
            nums.push_back(rev);
        }
        unordered_set<int> s;
        for(int i =0 ; i< nums.size(); i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};
int main(){
    Solution s;
    vector<int> nums={1,12,13,10, 14,07};
    cout<<s.CountDistinctIntegers(nums);
}