class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        
        
        for(int curAmount=1;curAmount<=amount;curAmount++){
            
            for(int index=0;index<n;index++){
                int coinVal=coins[index];
                
                if(curAmount>=coinVal)
                    dp[curAmount]=min(dp[curAmount],dp[curAmount-coinVal]);
                    
            }
            
            if(dp[curAmount]!=INT_MAX)
                dp[curAmount]++;
        }
        
        if(dp[amount]==INT_MAX)
            return -1;
        
        return dp[amount];
        
        
    }
};