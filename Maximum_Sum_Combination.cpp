/**************************************
Problem Description

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



Problem Constraints
 1 <= N <= 105

 1 <= A[i] <= 103

 1 <= C <= N



Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.



Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:

The returned array must be sorted in non-increasing order.



Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]


Example Explanation
Explanation 1:

 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
Explanation 2:

 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
**********************************/

struct Pair{
  int value,index1,index2;
};

class Compare{
  public:
  bool operator()(const Pair &p1,const Pair &p2){
      return p1.value<p2.value;
  }  
};

vector<int> Solution::solve(vector<int> &nums1, vector<int> &nums2, int k) {
    
    // Using Heaps and maps
    
    int n=nums1.size();
    sort(nums1.begin(),nums1.end(),greater<int>());
    sort(nums2.begin(),nums2.end(),greater<int>());
    
    priority_queue<Pair,vector<Pair>,Compare>pq;
    pq.push({nums1[0]+nums2[0],0,0});
    int count=0;
    
    map<pair<int,int>,bool>hashMap;
    vector<int>res;
    
    while(true){
        auto ele=pq.top();
        pq.pop();
        
        int value=ele.value;
        int index1=ele.index1;
        int index2=ele.index2;
        
        res.push_back(value);
        
        count++;
        if(count==k)
        return res;
        
        if(index1+1<n and hashMap.find({index1+1,index2})==hashMap.end()){
            pq.push({nums1[index1+1]+nums2[index2],index1+1,index2});
            hashMap[{index1+1,index2}]=true;
        }
        
        if(index2+1<n and hashMap.find({index1,index2+1})==hashMap.end()){
            pq.push({nums1[index1]+nums2[index2+1],index1,index2+1});
            hashMap[{index1,index2+1}]=true;
        } 
        
    }
    
    return res;
    
}
