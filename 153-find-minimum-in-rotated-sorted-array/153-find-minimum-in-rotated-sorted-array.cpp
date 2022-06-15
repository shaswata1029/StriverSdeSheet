class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        int min_element=nums[0];
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            min_element=min(min_element,nums[mid]);
            
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high])
                high=mid-1;
            else if(nums[low]<=nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        
        return min_element;
        
    }
};