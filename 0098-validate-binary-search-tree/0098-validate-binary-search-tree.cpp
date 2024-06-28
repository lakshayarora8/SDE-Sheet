class Solution {
public: 

    void preorder(TreeNode* root,vector<int> &vec)
    {
        if(!root)
        return ;

        preorder(root->left,vec);
        vec.push_back(root->val);
        preorder(root->right,vec);
    }
    bool isValidBST(TreeNode* root) {

        vector<int> vec;
        preorder(root,vec);
        
        for(int i=0;i<vec.size()-1;i++)
        {
            if(vec[i] >= vec[i+1])
            return false;
        }
        return true;
    }
};