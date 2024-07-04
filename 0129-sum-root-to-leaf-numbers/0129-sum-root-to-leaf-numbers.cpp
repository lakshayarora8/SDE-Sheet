class Solution {
public:
    int ans=0;
    void solve(TreeNode* root,int sum)
    {
        if(root == NULL)
        return;
        sum=sum*10+(root->val);
        if(!root->left && !root->right)
        {
            ans+=sum;
            return;
        }
        solve(root->left,sum);
        solve(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};