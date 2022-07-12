class Solution {
public:
    
    int findMinDistance(string &str1,string &str2,int n,int m,vector<vector<int>>&dp){
        if(n==0)
            return m;
        
        if(m==0)
            return n;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int ans;
        if(str1[n-1]==str2[m-1])
            ans=findMinDistance(str1,str2,n-1,m-1,dp);
        else{
            int insertDistance=findMinDistance(str1,str2,n,m-1,dp);
            int deleteDistance=findMinDistance(str1,str2,n-1,m,dp);
            int replaceDistance=findMinDistance(str1,str2,n-1,m-1,dp);
            ans=1+min(insertDistance,min(deleteDistance,replaceDistance));
        }
        
        return dp[n][m]=ans;
    }
    
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return findMinDistance(word1,word2,n,m,dp);
        
    }
};