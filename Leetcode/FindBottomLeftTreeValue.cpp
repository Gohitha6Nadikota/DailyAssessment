
/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/


class Solution {
public:
    int val=0,prev=-1;
    void dfs(TreeNode* root,int level)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            if(level>prev)
            {
                val=root->val;
                prev=level;
            }
        }
        
        if(root->left)
            dfs(root->left,level+1);
        if(root->right)
            dfs(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root)
    {
        dfs(root,0);
        return val;
    }
};