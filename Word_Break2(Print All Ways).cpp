#include<bits/stdc++.h>

void wordBreak(string &s,int last_index,int cur_index,int n,unordered_map<string,int>&hashMap,vector<string>&words,vector<string>&res){
    
    if(cur_index==n){
        
        string str="";
        for(auto &word:words){
            str+=word;
            str.push_back(' ');
        }
        
        str.pop_back();
        res.push_back(str);
        return;
    }
    
    string str=s.substr(last_index,cur_index-last_index+1);
    if(hashMap.find(str)!=hashMap.end()){
        words.push_back(str);
        wordBreak(s,cur_index+1,cur_index+1,n,hashMap,words,res);
        words.pop_back();
    }
    
    if(cur_index==n-1)
        return;
    
    wordBreak(s,last_index,cur_index+1,n,hashMap,words,res);
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    int n=s.size();
    vector<string>words;
    vector<string>res;
    
    unordered_map<string,int>hashMap;
    
    for(auto &word:dictionary){
        hashMap[word]=1;
    }
    
    wordBreak(s,0,0,n,hashMap,words,res);
        return res;

}
