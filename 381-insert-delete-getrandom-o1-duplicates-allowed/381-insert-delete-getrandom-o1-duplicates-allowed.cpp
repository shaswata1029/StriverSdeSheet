class RandomizedCollection {
public:
    
    vector<int>v;
    unordered_map<int,unordered_set<int>>myMap;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool present=false;
        
        if(myMap.find(val)!=myMap.end() && myMap[val].size()!=0)
            present=true;
        
        int index=v.size();
        myMap[val].insert(index);
        v.push_back(val);
        
        return !present;
    }
    
    bool remove(int val) {
        if(myMap.find(val)==myMap.end() || myMap[val].size()==0)
            return false;
        
        int index=*(myMap[val].begin());
        
        if(index==v.size()-1){
            v.pop_back();
            myMap[val].erase(index);
            return true;
        }
        
        
        int lastVal=v.back();
        
         myMap[val].erase(index);
        myMap[lastVal].erase(v.size()-1);
        myMap[lastVal].insert(index);
        
        v[index]=lastVal;
        v.pop_back();
        
       
     
        return true;
    }
    
    int getRandom() {
        
        int randIndex=rand()%v.size();
        return v[randIndex];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */