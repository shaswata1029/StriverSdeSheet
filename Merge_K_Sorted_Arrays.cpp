
#include<bits/stdc++.h>

struct HeapNode{
  int value,index,arrayIndex;  
};

class Compare{
    public:
  bool operator()(const HeapNode &node1,const HeapNode &node2){
      return node1.value>node2.value;
  }  
};

vector<int> mergeKSortedArrays(vector<vector<int>>&nums, int k)
{
    // Write your code here. 
    int n=nums.size();
    priority_queue<HeapNode,vector<HeapNode>,Compare>pq;
    
    for(int i=0;i<n;i++){
        auto &array=nums[i];
        pq.push({array[0],0,i});
    }
    
    vector<int>res;
    
    while(!pq.empty()){
        auto node=pq.top();
         pq.pop();
        
        int value=node.value;
        int index=node.index;
        int arrayIndex=node.arrayIndex;
        
        
        
        res.push_back(value);
        
        if(index+1<nums[arrayIndex].size())
            pq.push({nums[arrayIndex][index+1],index+1,arrayIndex});
    }
    
    return res;
    
    
}
