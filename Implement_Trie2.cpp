class Node{
    vector<Node*>child;
    int prefixCount;
    int endsWith;
    
    public:
    
    Node(){
        for(int index=0;index<26;index++)
            child.push_back(NULL);
        prefixCount=0;
        endsWith=0;
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
    
    void increasePrefixCount(){
        prefixCount++;
    }
    
    void decreasePrefixCount(){
        prefixCount--;
    }
    
    int getPrefixCount(){
        return prefixCount;
    }
    
    void increaseEndsWith(){
        endsWith++;
    }
    
    void decreaseEndsWith(){
        endsWith--;
    }
    
    int getEndsWith(){
        return endsWith;
    }
    
};

class Trie{
Node *root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node=root;
        
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            
            if(!node->containsKey(ch)){
                node->put(ch);
            }
            node=node->getNext(ch);
            node->increasePrefixCount();
        }
        node->increaseEndsWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node=root;
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            if(!node->containsKey(ch))
                return 0;
            node=node->getNext(ch);
        }
        
        return node->getEndsWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node=root;
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            
            if(!node->containsKey(ch))
                return 0;
            node=node->getNext(ch);
        }
        
        return node->getPrefixCount();
        
    }

    void erase(string &word){
        // Write your code here.
        
        Node *node=root;
        int n=word.size();
        
        for(int index=0;index<n;index++){
            char ch=word[index];
            node=node->getNext(ch);
            node->decreasePrefixCount();
        }
        
        node->decreaseEndsWith();
    }
};
