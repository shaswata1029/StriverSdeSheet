class Solution {
public:
    int minCut(string s) {
        
        int n=s.size();
        vector<vector<bool>>isPalindrome(n,vector<bool>(n,false));
        
        for(int gap=0;gap<n;gap++){
            int index1=0;
            int index2=gap;
            
            while(index2<n){
                
                if(gap==0)
                    isPalindrome[index1][index2]=true;
                else if(gap==1){
                    if(s[index1]==s[index2])
                        isPalindrome[index1][index2]=true;
                }else{
                    if(s[index1]==s[index2] && isPalindrome[index1+1][index2-1])
                        isPalindrome[index1][index2]=true;
                }
                
                index1++;
                index2++;
            }
        }
        
        
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        
        for(int index1=1;index1<n;index1++){
            if(isPalindrome[0][index1])
                dp[index1]=0;
            else{
                for(int index2=0;index2<index1;index2++){
                    if(isPalindrome[index2+1][index1])
                        dp[index1]=min(dp[index1],dp[index2]);
                }
                
                dp[index1]++;
            }
            
        }
        
        
        return dp[n-1];
    }
};