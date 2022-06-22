class Solution {
public:
    
    void findMaxLength(vector<string>&words,int index,int n,vector<int>&freq,int curLength,int &maxLength){
        if(index==n){
            maxLength=max(maxLength,curLength);
            return;
        }
        
        findMaxLength(words,index+1,n,freq,curLength,maxLength);
        string &word=words[index];
        int size=word.size();
        
        bool possible=true;
        for(auto ch:word){
            freq[ch-'a']++;
            if(freq[ch-'a']>1)
                possible=false;
        }
        
        if(possible)
            findMaxLength(words,index+1,n,freq,curLength+size,maxLength);
        
        for(auto ch:word)
            freq[ch-'a']--;

    }
    
    int maxLength(vector<string>& words) {
        
        int n=words.size();
        int maxLength=0;
        vector<int>freq(26,0);
        
        findMaxLength(words,0,n,freq,0,maxLength);
        return maxLength;
    }
};