class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edgeEle, int time, int change) {
        
        vector<vector<int>>edges(n);
        
        for(auto &ele:edgeEle){
            int x=ele[0];
            int y=ele[1];
            x--;
            y--;
          
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        vector<int>visited(n,0);
        priority_queue<pair<int,int>>pq;
        
        dist1[0]=0;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            
            int curTime=abs(ele.first);
            int node=ele.second;
            
            if(visited[node]>=2)
                continue;
            else
                visited[node]++;
            
            int newTime=curTime;
            int quo=curTime/change;
            if(quo%2==1)
                newTime=(quo+1)*change;
            
            for(auto nbr:edges[node]){
                if(dist1[nbr]>newTime+time){
                    dist1[nbr]=newTime+time;
                    pq.push({-dist1[nbr],nbr});
                }
                else if(dist1[nbr]!=newTime+time && dist2[nbr]>newTime+time){
                    dist2[nbr]=newTime+time;
                    pq.push({-dist2[nbr],nbr});
                }
            }
        }
        
        
        return dist2[n-1];
        
        
        
        
    }
};