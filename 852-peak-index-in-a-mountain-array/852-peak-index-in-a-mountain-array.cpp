class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int len=arr.size();
        int low=0;
        int high=len-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int cur_val=arr[mid];
            int prev_val=(mid==0?INT_MIN:arr[mid-1]);
            int next_val=(mid==len-1?INT_MIN:arr[mid+1]);
            
            if(prev_val<cur_val && cur_val>next_val)
                return mid;
            else if(prev_val<cur_val)
                low=mid+1;
            else 
                high=mid-1;
        }
        
        return -1;
        
    }
};