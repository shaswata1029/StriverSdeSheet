class Solution {
public:
    void generateCombinations(vector<int>&nums,int idx,int n,int target,vector<int>&combination,vector<vector<int>>&res){
        
        if(target<0)
            return;
        
        if(idx==n){
            if(target==0)
                res.push_back(combination);
            return;
        }
    
        generateCombinations(nums,idx+1,n,target,combination,res);
        combination.push_back(nums[idx]);
        generateCombinations(nums,idx,n,target-nums[idx],combination,res);
        combination.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        sort(candidates.begin(),candidates.end(),greater<int>());
        vector<int>combination;
        vector<vector<int>>res;
        generateCombinations(candidates,0,n,target,combination,res);
        
        return res;
        
    }
};