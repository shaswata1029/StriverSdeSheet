typedef long long ll;
class Solution {
public:
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        return p1.first>p2.first;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        int MOD=1e9+7;
        vector<pair<int,int>>nums(n);
        
        for(int i=0;i<n;i++)
            nums[i]={efficiency[i],speed[i]};
        
        sort(nums.begin(),nums.end(),compare);
        priority_queue<int,vector<int>,greater<int>>pq;
        
        ll maxAns=0;
        ll sumSpeed=0;
        
        for(int i=0;i<n;i++){
            int curEfficiency=nums[i].first;
            int curSpeed=nums[i].second;
            
            sumSpeed+=curSpeed;
            
            if(pq.size()==k){
                int minSpeed=pq.top();
                pq.pop();
                sumSpeed-=minSpeed;
            }
            
            ll ans=sumSpeed*curEfficiency;
            maxAns=max(maxAns,ans);
            
            pq.push(curSpeed);
        }
        
        return maxAns%MOD;
        
    }
};