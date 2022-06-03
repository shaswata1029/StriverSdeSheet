class Solution {
public:
    int findTotalPaths(int row,int col,int m,int n,vector<vector<int>>&dp){
        if(row==m-1 and col==n-1)
            return 1;
        
        if(row>=m or col>=n)
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        return dp[row][col]=findTotalPaths(row+1,col,m,n,dp)+findTotalPaths(row,col+1,m,n,dp);
    }
    
    int uniquePaths(int m, int n) {
        
//         using dynamic programming
//         better than recursive
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int total=findTotalPaths(0,0,m,n,dp);
        return total;
        
//         using combinatorics
//             most optimal
//         int N=(m+n-2);
//         int rows=(m-1);
        
//         double total=1;
        
//         for(int i=1;i<=rows;i++){
//             total=total*(N-rows+i)/i;
//         }
        
//         return (int)total;
        
    }
};