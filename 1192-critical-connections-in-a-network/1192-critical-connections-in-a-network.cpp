class Solution {
public:
    void dfs(int node,vector<vector<int>>&edges,vector<bool>&visited,vector<int>&parent, vector<int>&disc,vector<int>&low,int &curTime,vector<vector<int>>&res){
        
        visited[node]=true;
        disc[node]=curTime;
        low[node]=curTime;
        curTime++;
        
        for(auto nbr:edges[node]){
            if(visited[nbr] && nbr!=parent[node]){
                low[node]=min(low[node],disc[nbr]);
            }else if(!visited[nbr]){
                parent[nbr]=node;
                dfs(nbr,edges,visited,parent,disc,low,curTime,res);
                
                low[node]=min(low[node],low[nbr]);
                
                if(low[nbr]>disc[node]){
                    res.push_back({node,nbr});
                }
                
            }
        }
        
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>edges(n);
        
        for(auto &connection:connections){
            int x=connection[0];
            int y=connection[1];
           
            
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        vector<bool>visited(n,false);
        vector<int>parent(n,-1),disc(n),low(n);
        vector<vector<int>>res;
        int curTime=0;
        
        dfs(0,edges,visited,parent,disc,low,curTime,res);
        
        return res;
    }
};