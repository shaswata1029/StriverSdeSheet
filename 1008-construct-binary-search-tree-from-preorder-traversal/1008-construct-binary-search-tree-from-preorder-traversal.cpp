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
class Solution {
public:
    TreeNode *buildBST(vector<int>&preorder,int &index,int n,int maxVal){
        if(index==n)
            return NULL;
        
        int curVal=preorder[index];
        
        if(curVal>maxVal)
            return NULL;
        
        TreeNode *node=new TreeNode(curVal);
        index++;
        node->left=buildBST(preorder,index,n,curVal);
        node->right=buildBST(preorder,index,n,maxVal);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        int index=0;
        TreeNode * root=buildBST(preorder,index,n,INT_MAX);
        return root;
        
    }
};