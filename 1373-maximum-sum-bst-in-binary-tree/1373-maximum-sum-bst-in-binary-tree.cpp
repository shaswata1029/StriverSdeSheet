/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue{
    public:
    int maxVal,minVal,sum;
    bool isBst;
    
    
    NodeValue(int maxVal,int minVal,int sum,bool isBst){
        this->maxVal=maxVal;
        this->minVal=minVal;
        this->sum=sum;
        this->isBst=isBst;
    }
};

class Solution {
public:
    
    NodeValue findMaxBst(TreeNode *root,int &maxSum){
        
        if(root==NULL)
            return NodeValue(INT_MIN,INT_MAX,0,true);
        
        auto left=findMaxBst(root->left,maxSum);
        auto right=findMaxBst(root->right,maxSum);
        
        int val=root->val;
        int newSum=left.sum+right.sum+val;
        int newMax=max(val,max(left.maxVal,right.maxVal));
        int newMin=min(val,min(left.minVal,right.minVal));
        bool isRootBst=false;
        
        if(left.maxVal<val && left.isBst && val<right.minVal && right.isBst){
            isRootBst=true;
            maxSum=max(maxSum,newSum);
        }
        
        
        return NodeValue(newMax,newMin,newSum,isRootBst);
    }
    
    
    int maxSumBST(TreeNode* root) {
        int maxSum=0;
        
        findMaxBst(root,maxSum);
        return maxSum;
    }
};