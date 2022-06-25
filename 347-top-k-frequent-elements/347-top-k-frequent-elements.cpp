class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        
        unordered_map<int,int>hashMap;
        
        for(int i=0;i<n;i++)
            hashMap[nums[i]]++;
        
        for(auto &ele:hashMap){
            int value=ele.first;
            int freq=ele.second;
            
           
            
            if(pq.size()>=k){
                int minFreq=abs(pq.top().first);
                
                if(freq>minFreq){
                    pq.pop();
                    pq.push({-freq,value});
                }
            }
            else
                pq.push({-freq,value});
        }
        
        vector<int>res;
        
        while(!pq.empty()){
            int value=pq.top().second;
            pq.pop();
            res.push_back(value);
        }
        
        return res;
        
    }
};