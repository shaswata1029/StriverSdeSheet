class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double median;
        int n=nums1.size();
        int m=nums2.size();
        int total=(n+m);
        
        
        
        int low=0;
        int high=n;
        
        while(low<=high){
            int mid=(high+low)/2;
            
            int idx1=mid;
            int idx2=(total+1)/2-idx1;
            
            // cout<<idx1<<" "<<idx2<<"\n";
            if(idx2<0){
                high=mid-1;
                continue;
            }
            
            if(idx2>m){
                low=mid+1;
                continue;
            }
            
            int val1=(idx1==n?INT_MAX:nums1[idx1]);
            int pval1=(idx1==0?INT_MIN:nums1[idx1-1]);
            int val2=(idx2==m?INT_MAX:nums2[idx2]);
            int pval2=(idx2==0?INT_MIN:nums2[idx2-1]);
            
            if(pval1<=val2 && pval2<=val1){
                if(total%2==0){
                    int lmax=max(pval1,pval2);
                    int rmin=min(val1,val2);
                    
                    median=(lmax+rmin)/2.0;
                    
                }else
                    median=max(pval1,pval2);
                return median;
            }else if(pval1>val2){
                high=mid-1;
            }else if(pval2>val1)
                low=mid+1;
            
        }
        
        return INT_MIN;
        
    }
};