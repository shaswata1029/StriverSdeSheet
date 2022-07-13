class Solution {
public:
    
    static bool compare(const vector<int>&v1,const vector<int>&v2){
        if(v1[0]!=v2[0])
        return v1[0]<v2[0];
        
        return v1[1]>v2[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int>lis;
        lis.push_back(envelopes[0][1]);
        
        for(int index=1;index<n;index++){
            int height=envelopes[index][0];
            int width=envelopes[index][1];
            
          
            if(width>lis.back())
                lis.push_back(width);
            else{
                int newIndex=lower_bound(lis.begin(),lis.end(),width)-lis.begin();
                lis[newIndex]=width;
            }
            
            
        }
        
        
        int ans=lis.size();
        return ans;
        
    }
};