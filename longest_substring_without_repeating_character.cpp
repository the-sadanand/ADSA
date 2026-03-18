#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {

    unordered_map<char,int> mp;
    int left = 0;
    int maxLen = 0;

    for(int right = 0; right < s.size(); right++){

        if(mp.count(s[right])){
            left = max(left, mp[s[right]] + 1);
            cout<<mp.count(s[right])<<" ";
        }

        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
int main(){

 cout<<lengthOfLongestSubstring("abcabcd");

}