class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n=nums.size();
        int start_idx=0;
        int cur_idx=0;
        int maxLen=0;
        
        while(cur_idx<n){
            
            if(nums[cur_idx]==1){
                while(cur_idx+1<n and nums[cur_idx+1]==1)
                    cur_idx++;
                maxLen=max(maxLen,cur_idx-start_idx+1);
            }
            
            cur_idx++;
            start_idx=cur_idx;
            
        }
        
        return maxLen;
        
    }
};