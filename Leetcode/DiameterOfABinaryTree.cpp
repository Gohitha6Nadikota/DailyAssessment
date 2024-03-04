/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

class Solution {
public:
    int func(TreeNode* root,int &a)
    {
        if(root==NULL)
            return 0;
        int l=func(root->left,a);
        int r=func(root->right,a);
        a=max(a,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a=0;
        func(root,a);
        return a;
    }
};