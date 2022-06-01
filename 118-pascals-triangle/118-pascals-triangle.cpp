class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // the value of the pascals triangle in the ith row and jth column is (i-1)C(j-1)
        // if the matrix is 1 indexed
        
//       Also in a particular row the value always starts and ends with 1
//         So for ith row and jth column we can actually use iCj=(i-j+1)*(iCj-1)/j;
//         Considerig for O based indexing
//         For 1 based indexing we just have to repace i and j with (i-1) and (j-1) respectively;
        
        
        vector<vector<int>>res;
        
        for(int i=0;i<numRows;i++){
            vector<int>row(i+1);
            row[0]=1;
            
            for(int j=1;j<i;j++)
                row[j]=res[i-1][j-1]+res[i-1][j];
            
            row[i]=1;
            res.push_back(row);
        }
        
        return res;
        
        
    }
};