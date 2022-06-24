class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
//         Using Sorting
        unordered_map<string,vector<string>>hashMap;
        
        for(auto &str:strs){
            string temp=str;
            sort(temp.begin(),temp.end());
            hashMap[temp].push_back(str);
        }
        
        vector<vector<string>>res;
        
        for(auto &ele:hashMap){
            res.push_back(ele.second);
        }
        
        return res;
    }
};