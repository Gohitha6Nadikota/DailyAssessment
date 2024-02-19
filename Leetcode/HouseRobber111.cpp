/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree.
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 
*/



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
    vector<int> func(TreeNode *root)
    {
        vector<int>v;
        if(root==NULL)
        {
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        vector<int>l=func(root->left);
        vector<int>r=func(root->right); 
        int pick= root->val+l[1]+r[1];
        int notpick = max(l[0],l[1])+max(r[1],r[0]);
        v.push_back(pick);
        v.push_back(notpick);
        return v;
    }
    int rob(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        vector<int>ans = func(root);
        return max(ans[0],ans[1]);
    }
};