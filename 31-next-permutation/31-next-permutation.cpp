class Solution {
public:
    
    void reverse(vector<int>&nums,int start,int end){
        
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
       
        int n=nums.size();
        int idx=-1;
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        
        if(idx!=-1){
            for(int i=n-1;i>idx;i--){
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    break;
                }
            }
        }
        
        reverse(nums,idx+1,n-1);
        
        
        
    }
};