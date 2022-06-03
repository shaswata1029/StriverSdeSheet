class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int cur_row=0,cur_col=m-1;
        
        while(cur_row<n and cur_col>=0){
            if(matrix[cur_row][cur_col]==target)
                return true;
            else if(target>matrix[cur_row][cur_col])
                cur_row++;
            else
                cur_col--;
        }
        
        return false;
        
    }
};