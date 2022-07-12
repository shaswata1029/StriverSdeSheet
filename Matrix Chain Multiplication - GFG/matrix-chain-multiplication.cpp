// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int findMinimumCost(int nums[],int left,int right,vector<vector<int>>&dp){
        if(right-left+1<=2)
        return 0;
        
        if(dp[left][right]!=-1)
        return dp[left][right];
        
        int minCost=INT_MAX;
        
        for(int index=left+1;index<right;index++){
            int leftCost=findMinimumCost(nums,left,index,dp);
            int rightCost=findMinimumCost(nums,index,right,dp);
            
            int totalCost=leftCost+rightCost+nums[left]*nums[index]*nums[right];
            minCost=min(minCost,totalCost);
        }
        
        
        return dp[left][right]=minCost;
        
        
    }

    int matrixMultiplication(int n, int nums[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int minCost=findMinimumCost(nums,0,n-1,dp);
        return minCost;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends