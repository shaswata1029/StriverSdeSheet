class Solution {
public:
    void computePrevSmaller(vector<int>&heights,vector<int>&prevSmaller,int n){
        stack<int>st;
        
        for(int index=0;index<n;index++){
            while(!st.empty() && heights[st.top()]>=heights[index])
                st.pop();
            
            if(st.empty())
                prevSmaller[index]=-1;
            else
                prevSmaller[index]=st.top();
            
            st.push(index);
        }
    }
    
    void computeNextSmaller(vector<int>&heights,vector<int>&nextSmaller,int n){
        stack<int>st;
        
        for(int index=n-1;index>=0;index--){
            while(!st.empty() && heights[st.top()]>=heights[index])
                st.pop();
            
            if(st.empty())
                nextSmaller[index]=n;
            else
                nextSmaller[index]=st.top();
            
            st.push(index);
        }
    }
    
    int getMaxArea(vector<int>&heights,int n){
        
        vector<int>prevSmaller(n),nextSmaller(n);
        
        computePrevSmaller(heights,prevSmaller,n);
        computeNextSmaller(heights,nextSmaller,n);
        
        int maxArea=0;
        for(int index=0;index<n;index++){
            int width=nextSmaller[index]-prevSmaller[index]-1;
            int height=heights[index];
            
            int curArea=height*width;
            maxArea=max(maxArea,curArea);
        }
      
         return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>heights(m,0);
        int maxArea=0;
        
        for(int row=0;row<n;row++){
            
            for(int col=0;col<m;col++){
                if(row==0)
                heights[col]=matrix[row][col]-'0';
                else{
                    if(matrix[row][col]=='0')
                        heights[col]=0;
                    else
                        heights[col]++;
                }
            }
            
            int curArea=getMaxArea(heights,m);
            maxArea=max(maxArea,curArea);
        }
        
        
        return maxArea;
    }
};