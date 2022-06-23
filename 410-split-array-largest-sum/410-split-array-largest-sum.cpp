class Solution {
public:
    
    bool isPossible(vector<int>&nums,int n,int m,int maxSum){
        int curSum=0;
        int count=1;
        
        int curIndex=0;
        while(curIndex<n){
            
            if(curSum+nums[curIndex]<=maxSum)
                curSum+=nums[curIndex];
            else{
                curSum=nums[curIndex];
                count++;
            }
            
            if(count>m)
                return false;
            
            curIndex++;
        }
        
        return true;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        
        int low=nums[0];
        int high=0;
        
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(isPossible(nums,n,m,mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
            
        }
        
            
            return ans;
    }
};