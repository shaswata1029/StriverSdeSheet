typedef long long ll;

bool isPossible(vector<int>&pages,int n,ll maxPages,int k){
     
     ll curPages=0;
     int count=1;
     
     for(int i=0;i<n;i++){
         if(curPages+pages[i]>maxPages){
             count++;
             curPages=pages[i];
         }
         else
         curPages+=pages[i];
         
         if(count>k)
         return false;
     }
     
     return true;
    
}

int Solution::books(vector<int> &pages, int k) {
    
    int n=pages.size();
    
    if(k>n)
    return -1;
    
    ll low=pages[0];
    ll high=0;
    
    for(int i=0;i<n;i++){
        low=max(low,(ll)pages[i]);
        high+=pages[i];
    }
    
    ll ans=-1;
    while(low<=high){
        
        ll mid=low+(high-low)/2;
        
        if(isPossible(pages,n,mid,k)){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    
    return ans;
    
}
