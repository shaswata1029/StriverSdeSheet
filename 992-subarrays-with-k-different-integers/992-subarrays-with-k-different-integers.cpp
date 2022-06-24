class Solution {
public:
    int countAtMostK(vector<int>&nums,int n,int k){
        if(k==0)
            return 0;
        
        map<int,int>m;
        
        int index1=0,index2=0;
        int count=0;
        
        while(index2<n){
            m[nums[index2]]++;
            
            while(index1<=index2 && m.size()>k){
                if(m[nums[index1]]==1)
                    m.erase(nums[index1]);
                else
                    m[nums[index1]]--;
                index1++;
            }
            
            
            count+=(index2-index1+1);
            index2++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n=nums.size();
        int count1=countAtMostK(nums,n,k);
        int count2=countAtMostK(nums,n,k-1);
        
        int count=count1-count2;
        return count;
    }
};