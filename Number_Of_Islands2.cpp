
#include<bits/stdc++.h>

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


bool isPossible(int row,int col,int n,int m){
    if(row>=0 && col>=0 && row<n && col<m)
        return true;
    return false;
}


int getIndex(int row,int col,int m){
    return row*m+col;
}


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &queries){
	// Write your code here.
    
    int total=n*m;
    DSU d(total);
    
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    vector<vector<int>>grid(n,vector<int>(m,0));
    vector<int>res;
    int count=0;
    
    
    for(auto &query:queries){
        int row=query[0];
        int col=query[1];
        
        if(grid[row][col]==1)
            res.push_back(count);
        else{
            grid[row][col]=1;
            count++;
            
            int idx1=getIndex(row,col,m);
            
            for(int k=0;k<4;k++){
                int nrow=row+dx[k];
                int ncol=col+dy[k];
                
                if(isPossible(nrow,ncol,n,m) && grid[nrow][ncol]==1){
                    int idx2=getIndex(nrow,ncol,m);
                    bool possible=d.merge(idx1,idx2);
                    if(possible)
                        count--;
                }
            }
            res.push_back(count);
        }
    }
    
    return res;
}
