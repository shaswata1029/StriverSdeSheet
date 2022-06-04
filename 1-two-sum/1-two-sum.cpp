class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        map<int,int>m;
        
        vector<int>res;
        
        for(int i=0;i<n;i++){
            int element=nums[i];
            int req_target=target-element;
            
            if(m.find(req_target)!=m.end()){
                res.push_back(m[req_target]);
                res.push_back(i);
                break;
            }
            
            m[element]=i;
        }
        
        return res;
        
    }
};