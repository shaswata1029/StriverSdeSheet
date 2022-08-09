class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        
        if(n==1)
            return 0;
        
        if(arr[0]>arr[1])
            return 0;
        
        if(arr[n-1]>arr[n-2])
            return n-1;
        
        int low=1;
        int high=n-2;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            
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