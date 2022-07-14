class Solution {
public:
    
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        if(p1.first!=p2.first)
            return p1.first<p2.first;
        
        return p1.second<p2.second;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();
        vector<pair<int,int>>times;
        
        for(int index=0;index<n;index++){
            
            int passengers=trips[index][0];
            int startTime=trips[index][1];
            int endTime=trips[index][2];
            
            times.push_back({startTime,passengers});
            times.push_back({endTime,-passengers});
        }
        
        sort(times.begin(),times.end(),compare);
        
        int size=times.size();
        
        int totalPeople=0;
        for(int index=0;index<size;index++){
            int curPeople=times[index].second;
            totalPeople+=curPeople;
            
            if(totalPeople>capacity)
                return false;
        }
        
        return true;
        
    }
};