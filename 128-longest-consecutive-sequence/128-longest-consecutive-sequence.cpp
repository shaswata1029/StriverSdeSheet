class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        set<int>hashSet;
        
       
        for(int i=0;i<n;i++)
            hashSet.insert(nums[i]);
        
         int max_length=0;
        
           for(auto element:hashSet){
               int prev_element=element-1;
               if(hashSet.find(prev_element)!=hashSet.end())
                   continue;
               int length=1;
               int next_element=element+1;
               
               while(hashSet.find(next_element)!=hashSet.end()){
                   length++;
                   next_element++;
               }
               
               max_length=max(max_length,length);
           }
        
        return max_length;
    }
};