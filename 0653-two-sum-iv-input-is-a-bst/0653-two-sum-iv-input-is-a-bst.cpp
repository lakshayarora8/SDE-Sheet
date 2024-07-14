class BST{

    private: 
    bool reverse=true;
    public:
    // isreverse=true -> before so root->right
    // isreverse=false -> next so root->left
    stack<TreeNode*> st;
    BST(TreeNode* root,bool isreverse)
    {
        reverse=isreverse;
        pushall(root);
    }
    int hasnext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode* temp=st.top();
        st.pop();
        if(reverse) 
        pushall(temp->left);
        else
        pushall(temp->right);
        return temp->val;
    }

    private:
    void pushall(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse == false)
            {
                root=root->left;
            }
            else
            {
                root=root->right; 
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BST l(root,false);
        BST r(root,true);

        int start=l.next();
        int end=r.next();

        while(start <end )
        {
            if(start + end == k)
            return true;
            else if(start + end< k)
            start=l.next();
            else
            end=r.next();
        }
        return false;
        
    }
};