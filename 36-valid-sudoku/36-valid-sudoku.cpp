class Solution {
public:
    bool isPossible(vector<vector<int>>&rows,vector<vector<int>>&cols,vector<vector<int>>&grids,int row,int col,int grid,int number){
        
        if(rows[row][number]==1)
            return false;
        
        if(cols[col][number]==1)
            return false;
        
        if(grids[grid][number]==1)
            return false;
        
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>>rows(9,vector<int>(10,0));
        vector<vector<int>>cols(9,vector<int>(10,0));
        vector<vector<int>>grids(9,vector<int>(10,0));
        
        
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]!='.'){
                    int grid=3*(row/3)+col/3;
                    int number=board[row][col]-'0';
                    
                    if(!isPossible(rows,cols,grids,row,col,grid,number))
                        return false;
                    
                    rows[row][number]=1;
                    cols[col][number]=1;
                    grids[grid][number]=1;
                }
            }
        }
        
        
        return true;
    }
};