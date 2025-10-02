#include<iostream>
#include<vector>
#include<string>
using namespace std;

int NoOfWords(string s){
      int no_of_actual_space =0;
      int add=0;
      for(int i =0 ; i<s.length() ; i++){
          if(s[i]!= ' ') add = 1;
          if(s[i]==' ') {
              no_of_actual_space +=add;
              add=0;
          }
      }
      if(s[s.length()-1]!=' ') no_of_actual_space;
      else no_of_actual_space--;
      int num_of_words = no_of_actual_space+1;
    return num_of_words;
}
string reverseWords(string s) {
    int num_of_words= NoOfWords(s);
    vector<string> v(num_of_words);
    int index =0;
    int add=0;
    for(int i =0 ; i< s.length() ; i++){
          if(s[i]!=' ') v[index]+=(s[i]);
          if(s[i]!= ' ') add = 1;
          if(s[i]==' ') {
              index +=add;
              add=0;
          }        
    }
    string revStr = "";
    for(int i=v.size()-1 ; i>=0 ; i--){
        revStr=revStr+v[i]+" ";
    }
    cout<<revStr<<endl;
    return revStr;

}

// second approach 
void  reverseWordsWithin(string s){
    int len = s.length();
    vector<string> v;
    string word = "";
    for(int i = len-1; i >= 0; i--){
        if(s[i] != ' '){
            word = s[i] + word;
        } else {
            if(!word.empty()){
                v.push_back(word);
                word = "";
            }
        }
    }
    if(!word.empty()) v.push_back(word);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size()-1) cout << " ";
    }
    cout << endl;
    return;
}

int main(){
    string s="      i   am   not  a  bad    boy   ";
    // cout<<NoOfWords(s)<<endl;
    // string ans=reverseWords(s);
    // cout<<ans;

    reverseWordsWithin(s);
    return 0;
    
}