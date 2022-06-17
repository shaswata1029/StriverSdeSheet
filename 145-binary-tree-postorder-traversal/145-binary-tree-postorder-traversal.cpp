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
    void postOrderTraversal(TreeNode *root,vector<int>&postorder){
        if(root==NULL)
            return;
        
        postOrderTraversal(root->left,postorder);
        postOrderTraversal(root->right,postorder);
        postorder.push_back(root->val);
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>postorder;
//         Recursive approach
//         postOrderTraversal(root,postorder);
        
//         Iterative approach
        TreeNode*cur=root;
        stack<TreeNode*>st;
        
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode*temp=st.top()->right;
                if(temp!=NULL){
                    cur=temp;
                }else{
                    temp=st.top();
                    st.pop();
                    
                    postorder.push_back(temp->val);
                    
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }
        
        
        
        
        
        return postorder;
        
    }
};