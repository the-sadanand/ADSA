// find the maximum numbers of string pairs

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count=0;
        for(int i =0 ; i< n ;i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            for(int j = i+1 ; j < n ; j++){
                if(rev==words[j]) count++;
            }
        }
        return count;
    }
};

class SolutioninN {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> s;
        for(int i = 0 ; i< n ;i++){
            s.insert(words[i]);
        }
        int count=0;
        for(int i =0 ; i< n ;i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            if(words[i]==rev) continue;
            if(s.find()==rev)count++;
            s.erase(words[i]);
        }
        return count;
    }
};

int main(){
    vector<string> strV;

}
