class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edgeEle) {
        
        int n=colors.size();
        vector<vector<int>>edges(n);
        vector<int>indegree(n,0);
        
        for(auto ele:edgeEle){
            int x=ele[0];
            int y=ele[1];
            
            indegree[y]++;
            edges[x].push_back(y);
        }
        
        vector<vector<int>>freq(n,vector<int>(26,0));
        queue<int>q;
      
        
        for(int node=0;node<n;node++){
            if(indegree[node]==0){
                q.push(node);
                freq[node][colors[node]-'a']++;
            }
            
        }
        
        int count=0;
        int maxFreq=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            
            for(auto nbr:edges[node]){
                indegree[nbr]--;
                
                for(int i=0;i<26;i++){
                    freq[nbr][i]=max(freq[nbr][i],freq[node][i]+(i==colors[nbr]-'a'?1:0));
                    maxFreq=max(maxFreq,freq[nbr][i]);
                }
                
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        if(count!=n)
            return -1;
        return maxFreq;
        
    }
};