int Solution::solve(vector<int> &nums, int k) {

   int n=nums.size();
   map<int,int>hashMap;

   int current_prefix_xor=0;
   hashMap[0]=1;
   int count=0;
  
//   Maintain a current prefix xor and we check whether the required xor is previously present or not using a hashmap. If it is present then we add the number of occurences
//   of that xor from the hashmap to our answer.
  
   for(int i=0;i<n;i++){
       current_prefix_xor^=nums[i];
       int required_xor=current_prefix_xor ^ k;

       if(hashMap.find(required_xor)!=hashMap.end())
       count+=hashMap[required_xor];

       hashMap[current_prefix_xor]++;
   }

   return count;



}
