class Solution {
public:
    int MAX=1e8;
    
    int dp[31][31][31];
    int findMinCost(vector<int>&stones,vector<int>&prefixSum,int left,int right,int k,int total){
        
        int n=right-left+1;
        
        if(n<k)
            return MAX;
        
        if(n==1)
            return 0;
        
        if(dp[left][right][k]!=-1)
            return dp[left][right][k];
    
        int minCost=MAX;
        
        if(k==1){
            int mergeCost=prefixSum[right]-(left==0?0:prefixSum[left-1]);
            int totalCost=mergeCost+findMinCost(stones,prefixSum,left,right,total,total);
          
            return dp[left][right][k]=min(minCost,totalCost);
        }

       
        for(int index=left;index<right;index++){
            int leftCost=findMinCost(stones,prefixSum,left,index,1,total);
            int rightCost=findMinCost(stones,prefixSum,index+1,right,k-1,total);
            
            int curCost=leftCost+rightCost;
            
            minCost=min(minCost,curCost);
        }
        
        return dp[left][right][k]=minCost;
            
    }
    
    void preCompute(vector<int>&stones,vector<int>&prefixSum,int n){
        
        for(int index=0;index<n;index++){
            prefixSum[index]=(index==0?0:prefixSum[index-1])+stones[index];
        }
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        vector<int>prefixSum(n,0);
        
        preCompute(stones,prefixSum,n);
        memset(dp,-1,sizeof(dp));
        int minCost=findMinCost(stones,prefixSum,0,n-1,1,k);
        
        if(minCost==MAX)
            return -1;
        
        return minCost;
    }
};