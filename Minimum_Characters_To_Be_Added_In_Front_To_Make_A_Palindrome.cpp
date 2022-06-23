int Solution::solve(string s) {
    
    int n=s.size();
    
    if(n==0)
    return 0;
    
    string str=s;
    str.push_back('#');
    reverse(s.begin(),s.end());
    str+=s;
    
    int size=str.size();
    
    vector<int>lps(size,0);
    int len=0;
    int curIndex=1;
  
    
    while(curIndex<size){
        if(str[len]==str[curIndex]){
            len++;
            lps[curIndex]=len;
            curIndex++;
        }else if(len>0)
        len=lps[len-1];
        else{
            curIndex++;
        }
    }
    
    return n-lps[size-1];
    
    
}
