class DSU{
  vector<int>parent;
    vector<int>rank;
    
    public:
    DSU(int n){
        for(int index=0;index<n;index++){
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

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU alice(n),bob(n);
        int count1=1,count2=1;
        int removedEdges=0;
        
        for(auto &edge:edges){
            if(edge[0]==3){
                int x=edge[1];
                int y=edge[2];
                x--;y--;
                
                bool ans1=alice.merge(x,y);
                bool ans2=bob.merge(x,y);
                
                if(ans1 || ans2){
                    count1++;
                    count2++;
                }else
                    removedEdges++;
            }
        }
        
      
        for(auto &edge:edges){
             int type=edge[0];
            if(type!=3){
               
                int x=edge[1];
                int y=edge[2];
                x--;y--;
               
                bool ans;
                if(type==1)
                    ans=alice.merge(x,y);
                else
                    ans=bob.merge(x,y);
                
                if(ans){
                    if(type==1)
                        count1++;
                    else
                        count2++;
                }else
                    removedEdges++;
               
            }
        }
        
        if(count1!=n || count2!=n)
            return -1;
        
        return removedEdges;
        
    }
};