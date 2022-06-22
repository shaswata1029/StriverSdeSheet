struct Pair{
    int val,index,numIndex;
};

class Compare{
  public:
    bool operator()(const Pair &p1,const Pair &p2)const {
        return p1.val<p2.val;
    }
};

class Solution {
public:
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n=nums.size();
        multiset<Pair,Compare>s;
        
        int minRange=INT_MAX;
        int start=-1,end=-1;
        
         for(int i=0;i<n;i++){
             s.insert({nums[i][0],0,i});
         }
        
        while(!s.empty()){
            auto it1=s.begin();
            auto it2=s.rbegin();
            
            int val1=(*it1).val;
            int index=(*it1).index;
            int numIndex=(*it1).numIndex;
            int val2=(*it2).val;
            
           
            if(val2-val1+1<minRange){
                minRange=(val2-val1+1);
                start=val1;
                end=val2;
            }
            
            s.erase(it1);
            if(index+1<nums[numIndex].size())
                s.insert({nums[numIndex][index+1],index+1,numIndex});
            else
                break;
        }
        
        
        return {start,end};
        
        
    }
};