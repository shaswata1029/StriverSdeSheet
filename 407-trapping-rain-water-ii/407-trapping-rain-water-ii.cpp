struct HeapNode{
  int height,row,col;  
};

class Compare{
  public:
    bool operator()(const HeapNode &node1,const HeapNode &node2){
        return node1.height>node2.height;
    }
};

class Solution {
public:
    
    bool isPossible(int row,int col,int n,int m){
        if(row>=0 && row<n && col>=0 && col<m)
            return true;
        return false;
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int n=heightMap.size();
        int m=heightMap[0].size();
        
        priority_queue<HeapNode,vector<HeapNode>,Compare>pq;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 || col==0 || row==n-1 || col==m-1){
                pq.push({heightMap[row][col],row,col});
                visited[row][col]=true;
                }
            }
        }
        
        int totalWater=0;
        while(!pq.empty()){
           auto node=pq.top();
           pq.pop();
            
           int  height=node.height;
           int row=node.row;
           int col=node.col;
            
           for(int k=0;k<4;k++){
               int nrow=row+dx[k];
               int ncol=col+dy[k];
               
               if(isPossible(nrow,ncol,n,m) && visited[nrow][ncol]==false){
                   if(heightMap[nrow][ncol]<height)
                       totalWater+=(height-heightMap[nrow][ncol]);
                   visited[nrow][ncol]=true;
                   int nheight=max(height,heightMap[nrow][ncol]);
                   pq.push({nheight,nrow,ncol});
               }
           } 
            
        }
        
        return totalWater;
        
    }
};