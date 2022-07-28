class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)
            return 0;
        
        int size=routes.size();
        
        map<int,vector<int>>buses;
        
        for(int bus=0;bus<size;bus++){
            auto &route=routes[bus];
            
            for(auto busStop:route)
                buses[busStop].push_back(bus);
        }
        
        vector<bool>visitedBus(size,false);
        unordered_map<int,int>visitedBusStop;
        
        queue<int>q;
        q.push(source);
        visitedBusStop[source]=0;
        
        while(!q.empty()){
            int busStop=q.front();
            q.pop();
            
            int dist=visitedBusStop[busStop];
            if(busStop==target)
                return dist;
            
            for(auto bus:buses[busStop]){
                if(!visitedBus[bus]){
                    visitedBus[bus]=true;
                    
                    for(auto newBusStop:routes[bus]){
                        if(visitedBusStop.find(newBusStop)==visitedBusStop.end()){
                            visitedBusStop[newBusStop]=dist+1;
                            q.push(newBusStop);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};