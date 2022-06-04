class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int,int>hashMap;
        
        int current_sum=0;
        hashMap[0]=1;
        
        int count=0;
        
        for(int i=0;i<n;i++){
            current_sum+=nums[i];
            int required_sum=current_sum-k;
            
            if(hashMap.find(required_sum)!=hashMap.end())
                count+=hashMap[required_sum];
            
            hashMap[current_sum]++;
        }
        
        
        return count;
        
    }
};