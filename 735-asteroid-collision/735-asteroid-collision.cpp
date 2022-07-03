class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n=asteroids.size();
        stack<int>st;
        
        for(int i=0;i<n;i++){
            int curSize=asteroids[i];
            
            if(curSize>0){
                st.push(curSize);
                continue;
            }
            
            while(!st.empty() && st.top()>0 && st.top()<abs(curSize))
                st.pop();
            
            if(!st.empty() && st.top()>0 && st.top()==abs(curSize))
                st.pop();
            else if(!st.empty() && st.top()<0)
                st.push(curSize);
            else if(st.empty())
                st.push(curSize);
        }
        
        vector<int>res;
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};