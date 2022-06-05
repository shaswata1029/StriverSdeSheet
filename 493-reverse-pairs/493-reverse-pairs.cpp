typedef long long ll;
class Solution {
public:
    
    int merge(vector<int>&nums,int left,int mid,int right){
        
        int ans=0;
        
        int idx1=left,idx2=mid+1;
        
        while(idx1<=mid and idx2<=right){
            if((ll)nums[idx1]>(ll)2*nums[idx2]){
                ans+=(mid-idx1+1);
                idx2++;
            }
            else
                idx1++;
        }
        
        idx1=left,idx2=mid+1;
        int size=right-left+1;
        vector<int>temp(size);
        int cur_idx=0;
        
        while(idx1<=mid and idx2<=right){
            if(nums[idx1]<nums[idx2])
                temp[cur_idx++]=nums[idx1++];
            else
                temp[cur_idx++]=nums[idx2++];
        }
        
        while(idx1<=mid)
            temp[cur_idx++]=nums[idx1++];
        
        while(idx2<=right)
            temp[cur_idx++]=nums[idx2++];
        
        cur_idx=0;
        while(cur_idx<size){
            nums[left+cur_idx]=temp[cur_idx];
            cur_idx++;
        }
        
        return ans;
        
    }
    
    
    int mergeSort(vector<int>&nums,int left,int right){
        if(left>=right)
            return 0;
        
        int mid=(left+right)/2;
        int ans1=mergeSort(nums,left,mid);
        int ans2=mergeSort(nums,mid+1,right);
        int ans3=merge(nums,left,mid,right);
        
        int ans=ans1+ans2+ans3;
        return ans;
    }
    
    
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        int ans=mergeSort(nums,0,n-1);
        
        
        return ans;
        
    }
};