class Solution {
public:
    void generateCombinations(vector<int>&nums,int index,int n,int target,vector<int>&combination,vector<vector<int>>&res){
        if(target<0)
            return;
        
        if(index==n){
            if(target==0)
                res.push_back(combination);
            return;
        }
        
        combination.push_back(nums[index]);
        generateCombinations(nums,index+1,n,target-nums[index],combination,res);
        combination.pop_back();
        
        while(index+1<n and nums[index+1]==nums[index])
            index++;
        generateCombinations(nums,index+1,n,target,combination,res);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        sort(candidates.begin(),candidates.end(),greater<int>());
        vector<int>combination;
        vector<vector<int>>res;
        
        generateCombinations(candidates,0,n,target,combination,res);
        
        return res;
        
    }
};