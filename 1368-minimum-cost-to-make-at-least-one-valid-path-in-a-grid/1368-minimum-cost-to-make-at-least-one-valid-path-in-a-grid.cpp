class Solution {
public:
    
    bool isPossible(int row,int col,int n,int m){
        if(row>=0 && col>=0 && row<n && col<m)
            return true;
        return false;
    }
    
    int minCost(vector<vector<int>>& grid) {
     
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>q;
        
        dist[0][0]=0;
        q.push_back({0,0});
        
        while(!q.empty()){
            auto ele=q.front();
            q.pop_front();
            
            int row=ele.first;
            int col=ele.second;
            
            for(int dir=0;dir<4;dir++){
                int nrow=row+dx[dir];
                int ncol=col+dy[dir];
                if(dir==grid[row][col]-1){
                    if(isPossible(nrow,ncol,n,m) && dist[nrow][ncol]>dist[row][col]){
                        dist[nrow][ncol]=dist[row][col];
                        q.push_front({nrow,ncol});
                    }
                }else{
                    if(isPossible(nrow,ncol,n,m) && dist[nrow][ncol]>dist[row][col]+1){
                        dist[nrow][ncol]=dist[row][col]+1;
                        q.push_back({nrow,ncol});
                    }
                }
            }
        }
        
        
        return dist[n-1][m-1];
        
        
        
        
        
    }
};