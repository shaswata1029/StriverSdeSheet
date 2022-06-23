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
class BSTIterator{
    stack<TreeNode*>nextStack;
    stack<TreeNode*>prevStack;
    
    public:
    BSTIterator(TreeNode *root){
        TreeNode *cur=root;
        
        while(cur!=NULL){
            nextStack.push(cur);
            cur=cur->left;
        }
        
        cur=root;
        while(cur!=NULL){
            prevStack.push(cur);
            cur=cur->right;
        }
    }
    
    int next(){
        if(nextStack.empty())
            return -1;
        
        TreeNode *cur=nextStack.top();
        nextStack.pop();
        int val=cur->val;
        
        cur=cur->right;
        
        while(cur!=NULL){
            nextStack.push(cur);
            cur=cur->left;
        }
        
        return val;
    }
    
    int before(){
        if(prevStack.empty())
            return -1;
        
        TreeNode *cur=prevStack.top();
        prevStack.pop();
        int val=cur->val;
        
        cur=cur->left;
        
        while(cur!=NULL){
            prevStack.push(cur);
            cur=cur->right;
        }
        
        return val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        
        if(root==NULL)
            return false;
        
        BSTIterator it(root);
        
        int left=it.next();
        int right=it.before();
        
        while(left<right){
            int sum=left+right;
            if(sum==target)
                return true;
            else if(sum>target)
                right=it.before();
            else
                left=it.next();
        }
        
        return false;
        
    }
};