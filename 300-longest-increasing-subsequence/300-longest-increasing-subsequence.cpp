class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>lis;
        lis.push_back(nums[0]);
        
        for(int index=1;index<n;index++){
            int curVal=nums[index];
            
            if(curVal>lis.back())
                lis.push_back(curVal);
            else{
                int newIndex=lower_bound(lis.begin(),lis.end(),curVal)-lis.begin();
                lis[newIndex]=curVal;
            }
        }
        
        int ans=lis.size();
        return ans;
        
    }
};