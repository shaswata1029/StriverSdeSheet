class Node{
  public:
    
      
    vector<Node*>child;
    bool isEnd;
    
    Node(){
        for(int index=0;index<26;index++)
            child.push_back(NULL);
        isEnd=false;
    }
    
    bool containsKey(char ch){
        if(child[ch-'a']==NULL)
            return false;
        
        return true;
    }
    
    void put(char ch){
        child[ch-'a']=new Node();
    }
    
    Node* getNext(char ch){
        return child[ch-'a'];
    }
    
    void setEnd(){
        isEnd=true;
    }
    
    bool getIsEnd(){
        return isEnd;
    }
    
    
};


class Trie {
public:
    
    Node *root;
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            
            if(!node->containsKey(ch)){
                node->put(ch);
            }
            
            node=node->getNext(ch);
            
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        
        Node *node=root;
        
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            
            if(!node->containsKey(ch))
                return false;
            
            node=node->getNext(ch);
        }
        
        if(node->getIsEnd())
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        
        Node *node=root;
        
        int n=prefix.size();
        
        for(int index=0;index<n;index++){
            char ch=prefix[index];
            
            if(!node->containsKey(ch))
                return false;
            
            node=node->getNext(ch);
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */