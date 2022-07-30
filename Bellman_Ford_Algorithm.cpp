// Bellman ford algorithm in Graphs

vector <int> bellman_ford(int n, vector<vector<int>> edges, int src) {
        // Code here
        
        int MAX=1e8;
          vector<int>dist(n,MAX);
         dist[src]=0;
    
    for(int index=1;index<=(n-1);index++){
        
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
          
            if(dist[u]!=MAX && dist[v]>dist[u]+wt)
                dist[v]=dist[u]+wt;
        }
    }
    
       return dist;
    }
