
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=1;

        while(!q.empty())
        {
            int size=q.size();
            flag=1-flag;
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);

                level.push_back(node->val);
            }
            if(flag)
            reverse(begin(level),end(level));
            ans.push_back(level);
        }
        return ans;
    }
};