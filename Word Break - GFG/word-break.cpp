// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

bool wordBreak(string &str,int n,int index,unordered_map<string,bool>&hashMap,vector<int>&dp){
    if(index==n)
    return true;
    
    if(dp[index]!=-1)
    return dp[index];
    
    string newStr="";
    
    bool possible=false;
    for(int curIndex=index;curIndex<n;curIndex++){
        newStr.push_back(str[curIndex]);
        if(hashMap.find(newStr)!=hashMap.end())
        possible = possible or wordBreak(str,n,curIndex+1,hashMap,dp); 
        
        if(possible)
        break;
    }
    
    return dp[index]=possible;
}

    int wordBreak(string A, vector<string> &B) {
        //code here
        
        int n=A.size();
        unordered_map<string,bool>hashMap;
        
        for(auto &str:B)
        hashMap[str]=true;
        
        vector<int>dp(n,-1);
        bool ans=wordBreak(A,n,0,hashMap,dp);
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends