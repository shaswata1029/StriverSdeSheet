class Solution {
public:
    
    vector<int> split(string &version,char ch){
        
        int n=version.size();
        vector<int>res;
        int number=0;
        
        int curIndex=0;
        
        while(curIndex<n){
            
            if(version[curIndex]==ch){
                res.push_back(number);
                number=0;
            }else{
               int digit=version[curIndex]-'0';
                number=number*10+digit;
            }
        
            curIndex++;
        }
        
        res.push_back(number);
        while(res.size()>0 and res.back()==0)
            res.pop_back();
        
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<int> nums1=split(version1,'.');
        vector<int> nums2=split(version2,'.');
        
        int n=nums1.size();
        int m=nums2.size();
        
        int size=min(n,m);
        
        for(int i=0;i<size;i++){
            if(nums1[i]>nums2[i])
                return 1;
            else if(nums1[i]<nums2[i])
                return -1;
        }
        
        if(n>m)
            return 1;
        else if(n<m)
            return -1;
        
        return 0;
        
    }
};