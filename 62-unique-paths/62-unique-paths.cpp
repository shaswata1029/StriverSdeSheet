class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N=(m+n-2);
        int rows=(m-1);
        
        double total=1;
        
        for(int i=1;i<=rows;i++){
            total=total*(N-rows+i)/i;
        }
        
        return (int)total;
        
    }
};