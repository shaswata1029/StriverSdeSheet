/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/



void addLeftBoundary(TreeNode<int>* root,vector<int>&boundary){
    if(root==NULL)
        return;
    
    if(root->left==NULL && root->right==NULL)
        return;
    
    boundary.push_back(root->data);
    if(root->left)
        addLeftBoundary(root->left,boundary);
    else
        addLeftBoundary(root->right,boundary);
}

void addLeaves(TreeNode<int> *root,vector<int>&boundary){
    if(root==NULL)
        return;
    
    addLeaves(root->left,boundary);
    addLeaves(root->right,boundary);
    
    if(root->left==NULL && root->right==NULL)
        boundary.push_back(root->data);
}

void addRightBoundary(TreeNode<int> *root,vector<int>&boundary){
    if(root==NULL)
        return;
    
    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->right)
        addRightBoundary(root->right,boundary);
    else
        addRightBoundary(root->left,boundary);
    
    boundary.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>boundary;
    boundary.push_back(root->data);
    addLeftBoundary(root->left,boundary);
    addLeaves(root->left,boundary);
    addLeaves(root->right,boundary);
    addRightBoundary(root->right,boundary);
    
    return boundary;
}
