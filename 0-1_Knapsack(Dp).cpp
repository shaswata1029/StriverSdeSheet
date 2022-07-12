#include<bits/stdc++.h>
int findMaxProfit(vector<int>&weights,vector<int>&values,int n,int curIndex,int curWeight,vector<vector<int>>&dp){
    if(curWeight<0)
        return INT_MIN;
    
    if(curIndex==n)
        return 0;
    
    if(dp[curIndex][curWeight]!=-1)
        return dp[curIndex][curWeight];
    
    int take=values[curIndex]+findMaxProfit(weights,values,n,curIndex+1,curWeight-weights[curIndex],dp);
    
    int notTake=findMaxProfit(weights,values,n,curIndex+1,curWeight,dp);
    
    int ans=max(take,notTake);
    return dp[curIndex][curWeight]=ans;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    int ans=findMaxProfit(weights,values,n,0,w,dp);
    return ans;
}
