class Solution {
public:
    
    int findLongestCommonSubsequence(string &s1,string &s2,int n,int m,vector<vector<int>>&dp){
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int ans;
        if(s1[n-1]==s2[m-1])
            ans=1+findLongestCommonSubsequence(s1,s2,n-1,m-1,dp);
        else
            ans=max(findLongestCommonSubsequence(s1,s2,n-1,m,dp),findLongestCommonSubsequence(s1,s2,n,m-1,dp));
        
        return dp[n][m]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return findLongestCommonSubsequence(text1,text2,n,m,dp);
        
    }
};