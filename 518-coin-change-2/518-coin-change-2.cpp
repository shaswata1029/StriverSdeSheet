class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<int>dp(amount+1,0);
        dp[0]=1;
        
        for(int index=0;index<n;index++){
            int coinVal=coins[index];
            
            for(int curAmount=coinVal;curAmount<=amount;curAmount++){
                dp[curAmount]+=dp[curAmount-coinVal];
            }
        }
        
        return dp[amount];
    }
};