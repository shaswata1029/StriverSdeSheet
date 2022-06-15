#include<bits/stdc++.h>
bool isPossible(vector<vector<int>>&matrix,int n,int m,int number,int k){
    
    int count=0;
    for(int i=0;i<n;i++){
        
        int low=0;
        int high=m-1;
        
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(matrix[i][mid]<=number){
                index=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        
        count+=(index+1);
        if(count>k)
        return true;
    }
    
    return false;
    
}

int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    
    int total=n*m;
    int k=(total-1)/2;
    
    int low=1;
    int high=1e9;
    
    int median=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isPossible(matrix,n,m,mid,k)){
            median=mid;
            high=mid-1;
        }else
        low=mid+1;
    }
    
    return median;
}
