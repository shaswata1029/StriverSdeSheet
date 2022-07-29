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
    
    // returning the edge index which causes a cycle  in case there is a cycle otherwise returning -1 signifying no cycle is present
//     This method of indentfying cycle in a directed graph can only be applied if we are sure there is a cycle in the graph and there is only one cycle since dsu applies mailny to undirected graphs
    
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
            
//             Setting the index of edge which is the first parent
            if(indegree[y]==-1)
                indegree[y]=index;
            else{
//                 If one node has two parents then there may or may not be a cylcle
                int ans=find(edges,n,index);
//                 check that using removing the current index if there is a cycle
//                 If a cycle is present even after removing the edge then the previous edge of the node is the answer
                if(ans!=-1)
                    removedEdge=indegree[y];
                else
//                If a cycle is not  present then this edge will be the answer
                    removedEdge=index;
                break;
            }
        }
        
    
//         One last case which may arise is every node has a parent including a root node which causes a cycle 
//         In that case we simply remove the last node which is causing a cycle by checking it with DSU
        if(removedEdge==-1){
            removedEdge=find(edges,n,-1);
        }
        
        vector<int>res=edges[removedEdge];
        return res;
        
    }
};