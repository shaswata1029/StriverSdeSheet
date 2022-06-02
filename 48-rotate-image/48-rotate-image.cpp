class Solution {
public:
    
    void reverse(vector<int>&row,int start,int end){
        while(start<end){
            swap(row[start],row[end]);
            start++;
            end--;
        }
    }
    
    void transpose(vector<vector<int>>&matrix,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        transpose(matrix,n);
        
        for(int i=0;i<n;i++)
            reverse(matrix[i],0,n-1);
        
        
        
    }
};