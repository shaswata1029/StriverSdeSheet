class Solution {
public:
    void dfs(map<string,multiset<string>>&edges,string node,vector<string>&res){
        
        if(edges.find(node)!=edges.end()){
        multiset<string>& curEdges=edges[node];
        
        while(curEdges.size()>0){
            auto it=curEdges.begin();
            string nbr=*it;
            curEdges.erase(it);
            
            dfs(edges,nbr,res);
        }
        }
        
        res.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string,multiset<string>>edges;
        
        for(auto &ticket:tickets){
            string from=ticket[0];
            string to=ticket[1];
            
            edges[from].insert(to);
        }
        
        vector<string>res;
        string src="JFK";
        dfs(edges,src,res);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};