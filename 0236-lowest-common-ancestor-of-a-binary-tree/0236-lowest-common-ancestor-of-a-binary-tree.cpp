class Solution {
public:

    bool path(TreeNode* root,vector<TreeNode*> &ans,int value)
    {
        if(!root)
        return false;

        ans.push_back(root);

        if(root->val == value )
        return true;

        if( path(root->left,ans,value) || path(root->right,ans,value))
        return true;

        ans.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pathp,pathq;
        path(root,pathp,p->val);
        path(root,pathq,q->val);
        TreeNode* ans=NULL;
        int i=0;
        while(i<pathp.size() && i<pathq.size())
        {
            if(pathp[i] -> val == pathq[i]->val)
            ans=pathp[i];
            else
            break;
            i++;
        }
        return ans;    
    }
};