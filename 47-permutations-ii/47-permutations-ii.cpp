class Solution {
public:
    
    void findPermutations(int n,vector<int>&permutation,unordered_map<int,int>&hashMap,vector<vector<int>>&res){
        
        if(permutation.size()==n){
            res.push_back(permutation);
            return;
        }
        
        for(auto &ele:hashMap){
            int number=ele.first;
            int freq=ele.second;
        
            if(freq>0){
            permutation.push_back(number);
            hashMap[number]--;
            findPermutations(n,permutation,hashMap,res);
            hashMap[number]++;
            permutation.pop_back();
            }
        }
        
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int>hashMap;
        vector<int>permutation;
        
        for(int i=0;i<n;i++)
            hashMap[nums[i]]++;
        
        vector<vector<int>>res;
        
        findPermutations(n,permutation,hashMap,res);
        
        return res;
        
    }
};