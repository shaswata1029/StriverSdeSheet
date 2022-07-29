class DSU{
    vector<int>parent;
    vector<int>rank;
    
    public:
    DSU(int n){
        for(int index=0;index<n;index++)
        {
            parent.push_back(index);
            rank.push_back(1);
        }
    }
    
    int find(int node){
        if(node==parent[node])
            return node;
        return parent[node]=find(parent[node]);
    }
    
    bool merge(int x,int y){
        int px=find(x);
        int py=find(y);
        
        if(px==py)
            return false;
        
        if(rank[px]>rank[py])
            parent[py]=px;
        else if(rank[py]>rank[px])
            parent[px]=py;
        else{
            parent[py]=px;
            rank[px]++;
        }
        
        return true;
    }    
};

int find(vector<vector<int>>&edges,int n,int edgeIndex){
    
    DSU d(n);
    
    for(int index=0;index<n;index++){
        if(index!=edgeIndex){
        auto &edge=edges[index];
            int x=edge[0];
            int y=edge[1];
            
            x--;
            y--;
        
        bool possible=d.merge(x,y);
        if(!possible)
            return index;
        }
    }
    
    return -1;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<int>indegree(n,-1);
        
        int removedEdge=-1;
        
        for(int index=0;index<n;index++)
        {
            auto &edge=edges[index];
            int x=edge[0];
            int y=edge[1];
            
            x--;
            y--;
            
            if(indegree[y]==-1)
                indegree[y]=index;
            else{
                int ans=find(edges,n,index);
                if(ans!=-1)
                    removedEdge=indegree[y];
                else
                    removedEdge=index;
                break;
            }
        }
        
    
        
        if(removedEdge==-1){
            removedEdge=find(edges,n,-1);
        }
        
        vector<int>res=edges[removedEdge];
        return res;
        
    }
};