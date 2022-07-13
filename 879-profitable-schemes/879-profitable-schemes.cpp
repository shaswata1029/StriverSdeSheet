class Solution {
public:
    int dp[101][101][101];
    int MOD=1e9+7;
    
    
    int countWays(vector<int>&group,vector<int>&profit,int n,int curIndex,int minProfit,int total){
        if(total<0)
            return 0;
        
        if(curIndex==n){
            if(minProfit==0)
                return 1;
            return 0;
        }
        
        if(dp[curIndex][minProfit][total]!=-1)
            return dp[curIndex][minProfit][total];
        
        long long count=0;
        int take=countWays(group,profit,n,curIndex+1,(minProfit<profit[curIndex]?0:minProfit-profit[curIndex]),total-group[curIndex]);
        count+=take;
        count=count%MOD;
        
        int notTake=countWays(group,profit,n,curIndex+1,minProfit,total);
        count+=notTake;
        count=count%MOD;
        
        return dp[curIndex][minProfit][total]=count;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size=group.size();
        
        memset(dp,-1,sizeof(dp));
        int totalWays=countWays(group,profit,size,0,minProfit,n);
        return totalWays;
    }
};