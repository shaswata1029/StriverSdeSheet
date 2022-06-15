#include<bits/stdc++.h>

bool isPossible(vector<int>&positions,int n,int dist,int players){
    
    int count=1;
    int last_index=0;
    int cur_index=1;
    
    
    while(cur_index<n){
        int diff=positions[cur_index]-positions[last_index];
        
        if(diff>=dist){
            count++;
            last_index=cur_index;
        }
        
        if(count>=players)
            return true;
        
        cur_index++;
    }
    
    return false;
    
}


int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    
    int low=1;
    int high=1e9;
    
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isPossible(positions,n,mid,c)){
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    
    return ans;
}
