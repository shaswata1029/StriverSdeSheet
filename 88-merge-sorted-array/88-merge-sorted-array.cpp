class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int idx1=m-1;
        int idx2=n-1;
        int cur_idx=m+n-1;
        
        while(idx1>=0 and idx2>=0){
            if(nums1[idx1]<nums2[idx2])
                nums1[cur_idx--]=nums2[idx2--];
            else
                nums1[cur_idx--]=nums1[idx1--];
        }
        
        while(idx2>=0)
            nums1[cur_idx--]=nums2[idx2--];
        
    }
};