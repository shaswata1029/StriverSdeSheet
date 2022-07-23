class Node{
  vector<Node*>child;
    
    public:
    Node(){
        for(int index=0;index<2;index++)
            child.push_back(NULL);
    }
    
    bool containsKey(int bit){
        if(child[bit]==NULL)
            return false;
        return true;
    }
    
    void put(int bit){
        child[bit]=new Node();
    }
    
    Node* getNext(int bit){
        return child[bit];
    }
    
};

class Trie{
  Node *root;
    int size;
    
    public:
    Trie(){
        root=new Node();
        size=0;
    }
    
    void insert(int num){
        Node *node=root;
        
        for(int index=30;index>=0;index--){
            int bit=(num>>index) & 1;
            if(!node->containsKey(bit)){
                node->put(bit);
            }
            
            node=node->getNext(bit);
        }
        
        size++;
    }
    
    int getMaxXor(int num){
        
        if(size==0)
            return -1;
        
        Node * node=root;
        
        int maxXor=0;
        for(int index=30;index>=0;index--){
            int bit=(num>>index) & 1;
            
            if(node->containsKey(!bit)){
                maxXor= maxXor |(1<<index);
                node=node->getNext(!bit);
            }
            else{
                node=node->getNext(bit);
            }
        }
        
        return maxXor;
        
    }
};


class Solution {
public:
    
    static bool compare(const vector<int>&v1,const vector<int>&v2){
        return v1[1]<v2[1];
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int size=queries.size();
        vector<vector<int>>newQueries;
        
        for(int index=0;index<size;index++){
            int x=queries[index][0];
            int m=queries[index][1];
            newQueries.push_back({x,m,index});
        }
        
        sort(newQueries.begin(),newQueries.end(),compare);
        
        Trie trie;
        vector<int>res(size);
        
        int curIndex=0;
        
        for(int index=0;index<size;index++){
            int x=newQueries[index][0];
            int m=newQueries[index][1];
            int queryNo=newQueries[index][2];
            
            while(curIndex<n && nums[curIndex]<=m){
                trie.insert(nums[curIndex]);
                curIndex++;
            }
            
            int curMaxXor=trie.getMaxXor(x);
            res[queryNo]=curMaxXor;
           
        }
        
        
        return res;
    }
};