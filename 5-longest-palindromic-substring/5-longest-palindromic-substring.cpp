class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,false));
        int start=0,end=0,maxLen=1;
        
        for(int gap=0;gap<n;gap++){
            int i=0;
            int j=gap;
            
            while(i<n && j<n){
                if(gap==0)
                    dp[i][j]=true;
                else if(gap==1)
                    dp[i][j]=(s[i]==s[j]);
                else
                    dp[i][j]=(s[i]==s[j] && (dp[i+1][j-1]));
                
                if(dp[i][j] && gap+1>maxLen){
                    maxLen=gap+1;
                    start=i;
                    end=j;
                }
                
                i++;
                j++;
            }
        }
        
        
        string res=s.substr(start,maxLen);
        return res;
    
    }
};