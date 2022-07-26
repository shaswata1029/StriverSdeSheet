struct Node{
    int distance,node,stops;
};


class Compare{
  public:
    bool operator()(const Node&node1,const Node&node2){
        return node1.distance>node2.distance;
    }
};


class Solution {
public:
    
    int findCheapestPrice(int n,vector<vector<pair<int,int>>>&edges,int src,int dest,int k){
        
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        
        for(int i=0;i<=k;i++)
            dist[src][0]=0;
        
        priority_queue<Node,vector<Node>,Compare>pq;
        pq.push({0,src,0});
        
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            
            int node=ele.node;
            int distance=ele.distance;
            int stops=ele.stops;
            
            for(auto nbrs:edges[node]){
                int nbr=nbrs.first;
                int cost=nbrs.second;
                
                if(stops+1<=k && dist[nbr][stops+1]>distance+cost){
                    dist[nbr][stops+1]=distance+cost;
                    pq.push({dist[nbr][stops+1],nbr,stops+1});
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<=k;i++)
            ans=min(ans,dist[dest][i]);
        
        return ans;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        
        vector<vector<pair<int,int>>>edges(n);
        
        for(auto &ele:flights){
            int from=ele[0];
            int to=ele[1];
            int cost=ele[2];
            
            edges[from].push_back({to,cost});
        }
        
        int ans=findCheapestPrice(n,edges,src,dest,k+1);
        if(ans==INT_MAX)
            ans=-1;
        return ans;
        
    }
};