class Solution {
public:
    bool static compare(const pair<double,int>&p1,pair<double,int>&p2){
        return p1.first<p2.first;
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n=quality.size();
        vector<pair<double,int>>nums(n);
        
        for(int i=0;i<n;i++){
            double ratio=wage[i]/(1.0*quality[i]);
            nums[i]={ratio,quality[i]};
            

        }
        
        sort(nums.begin(),nums.end(),compare);
        
        double minCost=1e15;
        
       priority_queue<int>pq;
       int sumQuality=0;
        
        
       for(int i=0;i<n;i++)
       {
           double curRatio=nums[i].first;
           int curQuality=nums[i].second;
           
           
           
           sumQuality+=curQuality;
           
           if(pq.size()==k){
               int maxQuality=pq.top();
               pq.pop();
               sumQuality-=maxQuality;
           }
           
           if(i>=(k-1)){
               double cost=curRatio*sumQuality;
               minCost=min(minCost,cost);
           }
           
           
           pq.push(curQuality);
       }
        
        return minCost;
        
    }
};