int maximumOnesRow(vector<vector<int>> &matrix)
{
    //    Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    
    int maxRowIndex=0;
    
    int rowIndex=0;
    int colIndex=m-1;
    
    while(rowIndex<n and colIndex>=0){
        
        if(matrix[rowIndex][colIndex]==1){
            while(colIndex>=0 and matrix[rowIndex][colIndex]==1)
                colIndex--;
            maxRowIndex=rowIndex;
        }
        

        rowIndex++;
        
    }
    
    return maxRowIndex;
    
    
}
