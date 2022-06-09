class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();
        int cur_idx=0;
        int last_idx=0;
        int maxLen=0;
        
        int count=0;
        while(cur_idx<n){
            if(nums[cur_idx]==0)
                count++;
            
            while(count>k && last_idx<=cur_idx){
                if(nums[last_idx]==0)
                    count--;
                last_idx++;
            }
            
            maxLen=max(maxLen,cur_idx-last_idx+1);
            
            cur_idx++;
        }
        
        return maxLen;
        
    }
};