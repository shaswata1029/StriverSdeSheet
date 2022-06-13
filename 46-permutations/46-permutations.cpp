class Solution {
public:
    
    void findPermutations(vector<int>&nums,int cur_index,int n,vector<vector<int>>&res){
        
        if(cur_index==n)
        {
            res.push_back(nums);
            return;
        }
        
        int index=cur_index;
        
        while(index<n){
            swap(nums[cur_index],nums[index]);
            findPermutations(nums,cur_index+1,n,res);
            swap(nums[cur_index],nums[index]);
            index++;
        }
        
        
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>res;
        findPermutations(nums,0,n,res);
        return res;
        
    }
};