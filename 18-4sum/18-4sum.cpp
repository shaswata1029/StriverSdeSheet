class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        
        for(int i=0;i<n-3;i++){
            
            int element1=nums[i];
            
            for(int j=i+1;j<n-2;j++){
                
                int element2=nums[j];
                
                int left=j+1;
                int right=n-1;
                int req_target=target-element1-element2;
                
                while(left<right){
                    
                    int sum=nums[left]+nums[right];
                    
                    if(sum==req_target){
                        res.push_back({element1,element2,nums[left],nums[right]});
                        while(left+1<right and nums[left]==nums[left+1])
                        left++;
                        while(right-1>left and nums[right]==nums[right-1])
                        right--;
                        left++;
                        right--;
                    }
                    else if(sum>req_target){
                        while(right-1>left and nums[right]==nums[right-1])
                        right--;
                        right--;
                }
                    else{
                        while(left+1<right and nums[left]==nums[left+1])
                        left++;
                        left++;
                    }
                    
                    
                }
                    
                while(j+1<n-2 and nums[j+1]==nums[j])
                  j++;
            }
            
            while(i+1<n-3 and nums[i+1]==nums[i])
                i++;
        }
        
        return res;
    }
};