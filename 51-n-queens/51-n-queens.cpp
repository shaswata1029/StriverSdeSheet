class Solution {
public:
    
    bool isPossible(vector<string>&board,int i,int j,int n){
        
//         Checking for Column
        for(int row=0;row<i;row++)
            if(board[row][j]=='Q')
                return false;
        
        int row=i-1,col=j-1;
        
//         Checking for Left Diagonal
        while(row>=0 and col>=0){
            
            if(board[row][col]=='Q')
                return false;
            
            row--;
            col--;
        }
        
        row=i-1;
        col=j+1;
        
//         Checking for Right Diagonal
        while(row>=0 and col<n){
            
            if(board[row][col]=='Q')
                return false;
            
            row--;
            col++;
        }
        
        
        return true;
    }
    
    void NQueens(vector<string>&board,int row,int n,vector<vector<string>>&res){
        
        if(row==n){
            res.push_back(board);
            return;
        }
        
        
        for(int col=0;col<n;col++){
            if(isPossible(board,row,col,n)){
                board[row][col]='Q';
                NQueens(board,row+1,n,res);
                board[row][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board;
        
        for(int row=0;row<n;row++){
            string str="";
            for(int col=0;col<n;col++)
                str.push_back('.');
            board.push_back(str);
        }
        
        vector<vector<string>>res;
        
        NQueens(board,0,n,res);
        
        return res;
        
    }
};