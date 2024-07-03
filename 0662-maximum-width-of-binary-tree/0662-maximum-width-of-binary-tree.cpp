class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty())
        {
            int n=q.size();
           
            ll i=q.front().second;
            ll lastindex=q.back().second;
            ans=max(ans,lastindex-i+1);
            while(n--)
            {
                TreeNode* node=q.front().first;
                ll index=q.front().second;
                q.pop();
                if(node->left) 
                q.push({node->left,2*index+1});
                if(node->right)
                q.push({node->right,2*index+2});
            }
        }
        return ans;
    }
};