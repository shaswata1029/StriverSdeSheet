// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    // n is the number of eggs
    // k is the number of floors
    
    int findMinMoves(int n,int k,vector<vector<int>>&dp){
        if(n==1)
        return k;
        
        if(k==0)
        return 0;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        
        int minMoves=INT_MAX;
        for(int curFloor=1;curFloor<=k;curFloor++){
            int eggBreak=findMinMoves(n-1,curFloor-1,dp);
            int eggNotBreak=findMinMoves(n,k-curFloor,dp);
            
            int curMoves=max(eggBreak,eggNotBreak);
            minMoves=min(minMoves,curMoves);
        }
        
        minMoves++;
        return dp[n][k]=minMoves;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int moves=findMinMoves(n,k,dp);
        return moves;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends