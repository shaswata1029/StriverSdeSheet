#include <bits/stdc++.h> 
typedef long long ll;

ll merge(ll *nums,int left,int mid,int right){
    int size=right-left+1;
    ll temp[size];
    
    int idx1=left,idx2=mid+1;
    int cur_idx=0;
    ll ans=0;
    
    while(idx1<=mid and idx2<=right){
        if(nums[idx1]<=nums[idx2])
            temp[cur_idx++]=nums[idx1++];
        else{
            ans+=(mid-idx1+1);
            temp[cur_idx++]=nums[idx2++];
        }
    }
    
    while(idx1<=mid)
        temp[cur_idx++]=nums[idx1++];
    
    while(idx2<=right)
        temp[cur_idx++]=nums[idx2++];
    
    cur_idx=0;
    while(cur_idx<size){
        nums[cur_idx+left]=temp[cur_idx];
        cur_idx++;
    }
    
    return ans;
    
}

ll mergeSort(ll *nums,int left,int right){
    if(left>=right)
        return 0;
    
    int mid=(left+right)/2;
    ll count=0;
    count+=mergeSort(nums,left,mid);
    count+=mergeSort(nums,mid+1,right);
    count+=merge(nums,left,mid,right);
    
    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    ll ans=mergeSort(arr,0,n-1);
    return ans;
}
