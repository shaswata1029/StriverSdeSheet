class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        int cur_idx=0;
        int new_idx=0;
        
        while(cur_idx<n){
            
            while(cur_idx+1<n and nums[cur_idx]==nums[cur_idx+1])
                cur_idx++;
            
            nums[new_idx]=nums[cur_idx];
            
            new_idx++;
            cur_idx++;
        }
        
        return new_idx;
        
    }
};