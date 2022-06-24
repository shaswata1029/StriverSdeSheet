class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
//         Using Sorting
//         unordered_map<string,vector<string>>hashMap;
        
//         for(auto &str:strs){
//             string temp=str;
//             sort(temp.begin(),temp.end());
//             hashMap[temp].push_back(str);
//         }
        
//           Using Map of Map
        map<map<char,int>,vector<string>>hashMap;
        
        for(auto &str:strs){
            map<char,int>freq;
            
            for(auto ch:str)
                freq[ch]++;
            hashMap[freq].push_back(str);
        }
        
        vector<vector<string>>res;
        
        for(auto &ele:hashMap){
            res.push_back(ele.second);
        }
        
        return res;
    
        
    }
};