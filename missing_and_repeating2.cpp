typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &nums) {

//    Without modifying the array(with the help of mathematical expressions)
  
    int n=nums.size();

    ll sum1=((ll)n*(n+1))/2;
    ll sum2=((ll)n*(n+1)*(2*n+1))/6;
    
    ll sum3=0,sum4=0;
    for(int i=0;i<n;i++){
        sum3+=nums[i];
        sum4+=(ll)nums[i]*nums[i];
    }

    ll diff=sum1-sum3;
    ll val=sum2-sum4;
    ll sum=val/diff;

    int missing=(sum+diff)/2;
    int repeating=(sum-diff)/2;

    return {repeating,missing};


}
