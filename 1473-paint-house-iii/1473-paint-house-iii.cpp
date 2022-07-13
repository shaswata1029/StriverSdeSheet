class Solution {
public:
    int MAX=1e9;
    
    int dp[101][21][101];
    
    int findMinCost(vector<int>&houses,vector<vector<int>>&cost,int n,int curIndex,int prevColor,int m,int target){
        if(target<0)
            return MAX;
        
        if(curIndex==n){
            if(target==0)
                return 0;
            return MAX;
        }
        
        if(dp[curIndex][prevColor][target]!=-1)
            return dp[curIndex][prevColor][target];
        
        int minCost=MAX;
        if(houses[curIndex]!=0){
            if(houses[curIndex]==prevColor)
                minCost=findMinCost(houses,cost,n,curIndex+1,prevColor,m,target);
            else
                minCost=findMinCost(houses,cost,n,curIndex+1,houses[curIndex],m,target-1);
        }
        else{
           for(int color=1;color<=m;color++){
               int curCost=cost[curIndex][color-1]+findMinCost(houses,cost,n,curIndex+1,color,m,(prevColor==color)?target:target-1);
               
               minCost=min(minCost,curCost);
           } 
        }
        
        return dp[curIndex][prevColor][target]=minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        memset(dp,-1,sizeof(dp));
        int minCost=findMinCost(houses,cost,n,0,0,m,target);
        if(minCost==MAX)
            return -1;
        
        return minCost;
    }
};