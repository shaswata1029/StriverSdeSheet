class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        
        int maxAns=0;
        int curAns=0;
        
        int start=0,end=n-1;
        
        while(start<=end){
            if(power>=tokens[start]){
                curAns++;
                power-=tokens[start];
                start++;
            }else if(curAns>0)
            {
                curAns--;
                power+=tokens[end];
                end--;
            }else
                break;
            maxAns=max(maxAns,curAns);
        }
        
        return maxAns;
        
    }
};