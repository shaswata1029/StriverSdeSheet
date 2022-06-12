class Solution {
public:
    
    void generateCombinations(int number,int k,int n,vector<int>&combination,vector<vector<int>>&res){
        
        if(n<0 || k<0)
            return;
        
        if(number==10){
            if(k==0 && n==0)
                res.push_back(combination);
            return;
        }
        
        
        generateCombinations(number+1,k,n,combination,res);
        
        combination.push_back(number);
        generateCombinations(number+1,k-1,n-number,combination,res);
        combination.pop_back();
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>combination;
        vector<vector<int>>res;
        
        generateCombinations(1,k,n,combination,res);
        
        return res;
        
        
    }
};