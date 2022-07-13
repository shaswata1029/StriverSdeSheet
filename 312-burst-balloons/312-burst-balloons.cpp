class Solution {
public:
    int findMaxCoins(vector<int>&nums,int n,int left,int right,vector<vector<int>>&dp){
        if(left>right)
            return 0;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        int maxCoins=INT_MIN;
        
        for(int lastIndex=left;lastIndex<=right;lastIndex++){
            int leftCoins=findMaxCoins(nums,n,left,lastIndex-1,dp);
            int rightCoins=findMaxCoins(nums,n,lastIndex+1,right,dp);
            
            int totalCoins=leftCoins+rightCoins+(left==0?1:nums[left-1])*nums[lastIndex]*(right==n-1?1:nums[right+1]);
            maxCoins=max(maxCoins,totalCoins);
        }
        
        return dp[left][right]=maxCoins;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=findMaxCoins(nums,n,0,n-1,dp);
        return ans;
        
    }
};