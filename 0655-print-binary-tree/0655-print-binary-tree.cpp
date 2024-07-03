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
    int height(TreeNode* root)
    {
        if(root == NULL)
        return 0;
        return 1+ max(height(root->left) , height(root->right));
    }
    void dfs(TreeNode* root,vector<vector<string>> &ans,int r,int c,int m,int n)
    {
        if(root == NULL)
        return;

        ans[r][c]=to_string(root->val);
        if (m-r-2 >= 0) {
        dfs(root->left,ans,r+1,c-(1<<m-r-2),m,n);
        dfs(root->right,ans,r+1,c+(1<<m-r-2),m,n);
        }
    }


    vector<vector<string>> printTree(TreeNode* root) {
        
        int m=height(root);
        int n=(1<<m)-1;

        vector<vector<string>> ans(m,vector<string> (n,""));

        dfs(root,ans,0,n/2,m,n);

        return ans;
    }
};