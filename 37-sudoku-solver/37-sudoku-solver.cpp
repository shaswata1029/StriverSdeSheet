class Solution {
public:
    
    bool isPossible(vector<vector<int>>&rows,vector<vector<int>>&columns,vector<vector<int>>&subgrids,int row,int col,int grid,int number){
        
        if(rows[row][number]==1)
            return false;
        
        if(columns[col][number]==1)
            return false;
        
        if(subgrids[grid][number]==1)
            return false;
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>&board,int row,int col,bool &isSolved,vector<vector<int>>&rows,vector<vector<int>>&columns,vector<vector<int>>&subgrids){
        
        if(row==9){
            isSolved=true;
           
        }
        
        if(isSolved)
            return;
        
        // if(row==8)
        // cout<<row<<" "<<col<<"\n";
        int grid=3*(row/3)+col/3;
        
        
        if(board[row][col]!='.'){
            if(col==8)
                solveSudoku(board,row+1,0,isSolved,rows,columns,subgrids);
            else
                solveSudoku(board,row,col+1,isSolved,rows,columns,subgrids);
            return;
        }
        
        int number;
        for(number=1;number<=9;number++){
            if(isPossible(rows,columns,subgrids,row,col,grid,number)){
                board[row][col]='0'+number;
                rows[row][number]=1;
                columns[col][number]=1;
                subgrids[grid][number]=1;
                
                if(col==8)
                  solveSudoku(board,row+1,0,isSolved,rows,columns,subgrids);
                else
                   solveSudoku(board,row,col+1,isSolved,rows,columns,subgrids);
                    
                
                if(isSolved)
                    return;
                
                rows[row][number]=0;
                columns[col][number]=0;
                subgrids[grid][number]=0;
                board[row][col]='.';
            }
        }
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>>rows(9,vector<int>(10,0)),columns(9,vector<int>(10,0)),subgrids(9,vector<int>(10,0));
        
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]!='.'){
                  int grid=3*(row/3)+col/3;
                  int number =board[row][col]-'0';
                  rows[row][number]=1;
                  columns[col][number]=1;
                  subgrids[grid][number]=1;  
                }
            }
        }
        
        bool isSolved=false;
        solveSudoku(board,0,0,isSolved,rows,columns,subgrids);
        
    }
};