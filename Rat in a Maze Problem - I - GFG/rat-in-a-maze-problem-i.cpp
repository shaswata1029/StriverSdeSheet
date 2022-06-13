// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    char position[4]={'U','L','D','R'};
    
    bool isPossible(vector<vector<int>>&board,int row,int col,int n){
        if(row>=0 and col>=0 and row<n and col<n and board[row][col]>0)
        return true;
        
        return false;
    }
    
    void findPaths(vector<vector<int>>&board,int row,int col,int n,string &path,vector<string>&res){
        
        if(row==n-1 and col==n-1){
            res.push_back(path);
            return;
        }
        
        
        for(int k=0;k<4;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];
            
            if(isPossible(board,nrow,ncol,n)){
                board[nrow][ncol]=-1;
                path.push_back(position[k]);
                
                findPaths(board,nrow,ncol,n,path,res);
                
                path.pop_back();
                board[nrow][ncol]=1;
            }
        }
         
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &board, int n) {
        // Your code goes here
        
        string path="";
        vector<string>res;
        
        if(board[0][0]==0 || board[n-1][n-1]==0)
        return res;
        
        board[0][0]=-1;
        findPaths(board,0,0,n,path,res);
        
        return res;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends