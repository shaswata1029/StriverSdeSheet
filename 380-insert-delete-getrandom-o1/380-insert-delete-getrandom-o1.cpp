class RandomizedSet {
     vector<int>v;
    unordered_map<int,int>myMap;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(myMap.find(val)!=myMap.end())
            return false;
        myMap[val]=v.size();
        v.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        if(myMap.find(val)==myMap.end())
            return false;
        
        int lastVal=v[v.size()-1];
        int index=myMap[val];
        
        myMap[lastVal]=index;
        myMap.erase(val);
        
        swap(v[index],v[v.size()-1]);
        v.pop_back();
        return true;
        
    }
    
    int getRandom() {
        int size=v.size();
        
        int randIndex=rand()%size;
        return v[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */