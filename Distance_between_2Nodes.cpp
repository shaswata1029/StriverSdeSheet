/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* findLCA(TreeNode<int>* root,int node1,int node2){
    if(root==NULL)
        return NULL;
    
    if(root->val==node1 || root->val==node2)
        return root;
    
    TreeNode<int>* left=findLCA(root->left,node1,node2);
    TreeNode<int>* right=findLCA(root->right,node1,node2);
    
    if(left!=NULL && right!=NULL)
        return root;
    
    if(left!=NULL)
        return left;
    
    return right;
}

int findLevel(TreeNode<int> *root,int node,int level){
    if(root==NULL)
        return -1;
    
    if(root->val==node)
        return level;
    
    int ans=findLevel(root->left,node,level+1);
    if(ans==-1)
        ans=findLevel(root->right,node,level+1);
    return ans;
}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    // Write your code here.
    
    TreeNode<int> *lca=findLCA(root,node1,node2);
    
    if(lca==NULL)
        return -1;
    
    int dist1=findLevel(lca,node1,0);
    int dist2=findLevel(lca,node2,0);
    
    return dist1+dist2;
}
