class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        
        int idx=0;
        
        vector<vector<int>>res;
        while(idx<n){
            
            int requiredSum=-nums[idx];
            int left=idx+1,right=n-1;
            
            while(left<right){
                int sum=nums[left]+nums[right];
                
                if(sum==requiredSum){
                    while(left+1<right and nums[left+1]==nums[left])
                        left++;
                    while(right-1>left and nums[right-1]==nums[right])
                        right--;
                    res.push_back({nums[idx],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(sum>requiredSum)
                    right--;
                else
                    left++;
            }
            
            
            while(idx+1<n and nums[idx+1]==nums[idx])
                idx++;
            idx++;
        }
        
        
        return res;
    }
};