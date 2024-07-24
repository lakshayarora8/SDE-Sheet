class Solution {
public:
    bool ans=false;
    void traversal(TreeNode* root, TreeNode* subRoot)
    {
        if(ans == true)
        return;
        if(root == NULL)
        return;

        if(root->val == subRoot->val)
        ans= identical(root,subRoot);
        traversal(root->left,subRoot);
        traversal(root->right,subRoot);
    }

    bool identical(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL || subRoot==NULL)
        return root==subRoot;
        return root->val == subRoot->val && identical(root->left,subRoot->left) && 
        identical(root->right,subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
      traversal(root,subRoot);
      return ans;
    }
};