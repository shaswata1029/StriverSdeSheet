class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n=nums.size();
        int start=0;
        int end=0;
        
        deque<int>q1,q2;
        int maxSize=1;
        
        
        int curMax=INT_MIN,curMin=INT_MAX;
        
        while(end<n){
            
            while(!q1.empty() && nums[end]>=nums[q1.back()])
                q1.pop_back();
            
            while(!q2.empty() && nums[end]<=nums[q2.back()])
                q2.pop_back();
            
            q1.push_back(end);
            q2.push_back(end);
            
            curMax=nums[q1.front()];
            curMin=nums[q2.front()];
            
            while(curMax-curMin>limit){
                
                if(!q1.empty() && q1.front()<=start)
                    q1.pop_front();
                
                if(!q2.empty() && q2.front()<=start)
                    q2.pop_front();
                
                curMax=nums[q1.front()];
                curMin=nums[q2.front()];
                start++;
            }
            
            maxSize=max(maxSize,end-start+1);
            end++;
        }
        
        return maxSize;
        
    }
};