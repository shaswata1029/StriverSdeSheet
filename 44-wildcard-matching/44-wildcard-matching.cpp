class Solution {
public:
    bool wildCardMatch(string &str,string &pattern,int n,int m,vector<vector<int>>&dp){
        
       
        if(n==0 && m==0)
            return true;
        
        if(m==0)
            return false;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(n==0){
            if(pattern[m-1]!='*')
            return dp[n][m]=false;
        else
            return dp[n][m]=wildCardMatch(str,pattern,n,m-1,dp);
        }
        
        bool ans=false;
        if(pattern[m-1]=='?')
            ans= wildCardMatch(str,pattern,n-1,m-1,dp);
        else if(pattern[m-1]=='*'){
            ans= wildCardMatch(str,pattern,n-1,m-1,dp);
            ans =ans || wildCardMatch(str,pattern,n-1,m,dp);
            ans = ans || wildCardMatch(str,pattern,n,m-1,dp);
        }
        else{
            ans= str[n-1]==pattern[m-1] && wildCardMatch(str,pattern,n-1,m-1,dp);
        }
        
        return dp[n][m]=ans;
        
        
    }
    
    bool isMatch(string s, string p) {
        
        int n=s.size();
        int m=p.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return wildCardMatch(s,p,n,m,dp);
        
    }
};