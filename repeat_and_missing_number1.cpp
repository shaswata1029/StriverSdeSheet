#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &nums, int n)
{
	// Write your code here 
  // With the help of hashing inside array(array modified)
    
     
    int missing=-1,repeating=-1;
    for(int i=0;i<n;i++){
        int val=abs(nums[i]);
        if(nums[val-1]<0)
        repeating=val;
        else
        nums[val-1]=-nums[val-1];
    }

    for(int i=0;i<n;i++){
        if(nums[i]>0){
        missing=i+1;
        break;
        }
    }

    return {missing,repeating};
	
}
