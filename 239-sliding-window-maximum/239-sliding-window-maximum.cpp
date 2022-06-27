class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        deque<int>maxQueue;
        
        for(int i=0;i<k;i++){
            while(!maxQueue.empty() && nums[maxQueue.back()]<nums[i])
                maxQueue.pop_back();
            maxQueue.push_back(i);
        }
        
        vector<int>res;
        res.push_back(nums[maxQueue.front()]);
        
        int index1=1;
        int index2=k;
        
        while(index2<n){
            if(maxQueue.front()<index1)
                maxQueue.pop_front();
            
            while(!maxQueue.empty() && nums[maxQueue.back()]<nums[index2])
                maxQueue.pop_back();
            maxQueue.push_back(index2);
            
            res.push_back(nums[maxQueue.front()]);
            
            index1++;
            index2++;
        }
        
        return res;
    
    }
};