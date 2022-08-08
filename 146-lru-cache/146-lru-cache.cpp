class LRUCache {
public:
    
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>myMap;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    void refreshPosition(int key,int value){
        cache.erase(myMap[key]);
        cache.push_front({key,value});
        myMap[key]=cache.begin();
    }
    
    int get(int key) {
        if(myMap.find(key)==myMap.end())
            return -1;
        
        auto it=myMap[key];
        int value=(*it).second;
        refreshPosition(key,value);
        return value;
    }
    
    void put(int key, int value) {
         if(myMap.find(key)!=myMap.end())
             refreshPosition(key,value);
        else{
            cache.push_front({key,value});
            myMap[key]=cache.begin();
            
            if(myMap.size()>capacity){
               int removedKey=cache.back().first;
                cache.pop_back();
                myMap.erase(removedKey);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */