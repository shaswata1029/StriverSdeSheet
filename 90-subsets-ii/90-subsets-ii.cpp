class Solution {
public:
    
    void findSubsets(vector<int>&nums,int index,int n,vector<int>&subset,vector<vector<int>>&res){
        if(index==n){
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        findSubsets(nums,index+1,n,subset,res);
        subset.pop_back();
        
        while(index+1<n and nums[index+1]==nums[index])
            index++;
        
        findSubsets(nums,index+1,n,subset,res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int>subset;
        vector<vector<int>>res;
        findSubsets(nums,0,n,subset,res);
        return res;
    }
};