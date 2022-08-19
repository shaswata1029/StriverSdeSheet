class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
      unordered_map<int,int>m;
        
        for(auto ele:nums)
            m[ele]++;
        
        for(auto ele:m){
            int val=ele.first;
            int freq=ele.second;
        
            
            int f1=0,f2=0,f3=0,f4=0;
            
            if(m.find(val-1)!=m.end())
                f1=m[val-1];
            
            if(m.find(val-2)!=m.end())
                f2=m[val-2];
            
            if(m.find(val+1)!=m.end())
                f3=m[val+1];
            
            if(m.find(val+2)!=m.end())
                f4=m[val+2];
            
//             acting as last
            int freq1=min(f1,f2);
//             acting as first
            int freq2=min(f3,f4);
            
//             acting as middle
            f1-=freq1;
            f3-=freq2;
            
            int freq3=min(f1,f3);
            if(freq1+freq2+freq3<freq)
                return false;
        }
        
        return true;
    }
};