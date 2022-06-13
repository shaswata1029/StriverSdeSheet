class Solution {
public:
    
    bool isPossible(map<int,int>&column,map<int,int>&leftDiagonal,map<int,int>&rightDiagonal,int row,int col)
    {
        
        if(column.find(col)!=column.end())
            return false;
        
        if(leftDiagonal.find(row-col)!=leftDiagonal.end())
            return false;
        
        if(rightDiagonal.find(row+col)!=rightDiagonal.end())
            return false;
        
        return true;
    }   
    
    void findTotal(int row,int n,map<int,int>&column,map<int,int>&leftDiagonal,map<int,int>&rightDiagonal,int &count){
        
        if(row==n)
        {
            count++;
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isPossible(column,leftDiagonal,rightDiagonal,row,col)){
                column[col]=1;
                leftDiagonal[row-col]=1;
                rightDiagonal[row+col]=1;
                
                findTotal(row+1,n,column,leftDiagonal,rightDiagonal,count);
                
                column.erase(col);
                leftDiagonal.erase(row-col);
                rightDiagonal.erase(row+col);
            }
        }
        
    }
    
    
    int totalNQueens(int n) {
        
        map<int,int>column,leftDiagonal,rightDiagonal;
        int count=0;
        
        findTotal(0,n,column,leftDiagonal,rightDiagonal,count);
        
        
        return count;
    }
};