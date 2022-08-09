class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        
        if(n==1)
            return 0;
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(mid==0 && arr[mid]>arr[mid+1])
                return mid;
            else if(mid==0){
                low=mid+1;
                continue;
            }
            
            if(mid==n-1 && arr[mid]>arr[mid-1])
                return mid;
            else if(mid==n-1){
                high=mid-1;
                continue;
            }
            
            int cur_val=arr[mid];
            int prev_val=arr[mid-1];
            int next_val=arr[mid+1];
            
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