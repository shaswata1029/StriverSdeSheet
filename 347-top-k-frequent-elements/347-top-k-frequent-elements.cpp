class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
//         Using Heaps
/******************
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
        
**********************************/  
        
//         Using Bucket Sort
        
        unordered_map<int,int>hashMap;
        vector<vector<int>>bucket(n+1);
        
        for(int i=0;i<n;i++)
            hashMap[nums[i]]++;
        
        for(auto &ele:hashMap){
            int value=ele.first;
            int freq=ele.second;
            
            bucket[freq].push_back(value);
        }
        
        vector<int>res;
        int count=0;
        
        int curFreq=n;
        
        while(curFreq>0){
            
            vector<int>& curBucket=bucket[curFreq];
            int size=curBucket.size();
            
            if(size!=0){
                
                int curIndex=size-1;
                
                while(curIndex>=0 && count<k){
                    res.push_back(curBucket[curIndex]);
                    count++;
                    curIndex--;
                }
            }
            
            if(count==k)
                return res;
            
            curFreq--;
        }
        
        
        return res;
        
        
    }
};