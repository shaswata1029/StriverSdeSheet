// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

   
   bool isSubsetSum(vector<int>&nums,int n,int curIndex,int curSum,vector<vector<int>>&dp){
       
       if(curSum<0)
       return false;
       
       if(curSum==0)
       return true;
       
       if(curIndex==n)
       return false;
       
      if(dp[curIndex][curSum]!=-1)
      return dp[curIndex][curSum];
       
       bool take=isSubsetSum(nums,n,curIndex+1,curSum-nums[curIndex],dp);
       bool notTake=isSubsetSum(nums,n,curIndex+1,curSum,dp);
       
       bool possible=take || notTake;
       
       return  dp[curIndex][curSum]=possible;
   }
   
    bool isSubsetSum(vector<int>nums, int sum){
        // code here 
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        bool ans=isSubsetSum(nums,n,0,sum,dp);
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends