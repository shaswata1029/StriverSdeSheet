class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        unordered_set<int>s;
        
       
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        
         int max_length=0;
        
           for(auto element:s){
               int prev_element=element-1;
               if(s.find(prev_element)!=s.end())
                   continue;
               int length=1;
               int next_element=element+1;
               
               while(s.find(next_element)!=s.end()){
                   length++;
                   next_element++;
               }
               
               max_length=max(max_length,length);
           }
        
        return max_length;
    }
};