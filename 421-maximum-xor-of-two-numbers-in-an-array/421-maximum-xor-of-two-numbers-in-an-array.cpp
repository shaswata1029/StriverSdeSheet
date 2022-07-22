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
  Node* root;
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        Node*node=root;
        
        for(int index=30;index>=0;index--){
            int bit=(num>>index) & 1;
            if(!node->containsKey(bit)){
                node->put(bit);
            }
            
            node=node->getNext(bit);
        }
    }
    
    int getMaxXor(int num){
        Node*node=root;
        
        int maxNum=0;
        for(int index=30;index>=0;index--){
            int bit=(num>>index) & 1;
            if(node->containsKey(!bit)){
                maxNum= maxNum |(1<<index);
                node=node->getNext(!bit);
            }else{
                node=node->getNext(bit);
            }
        }
        
        return maxNum;
    }
    
};

class Solution {
public:
    
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie trie;
        
        int size=nums.size();
        
        for(int index=0;index<size;index++){
            int num=nums[index];
            trie.insert(num);
        }
        
        int maxXor=0;
        
        for(int index=0;index<size;index++){
            int curXor=trie.getMaxXor(nums[index]);
            maxXor=max(maxXor,curXor);
        }
        
        return maxXor;
        
    }
};