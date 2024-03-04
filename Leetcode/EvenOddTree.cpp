/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1,
 their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in
 strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in
strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
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
/*class Solution {
public:
    vector<vector<int>>v;
    void func(TreeNode* root)
    {
        if(root==NULL)
            return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v1;
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                v1.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            v.push_back(v1);
        }
            
    }
    
    bool isEvenOddTree(TreeNode* root) {
     func(root);
     for(int i=0;i<v.size();i++)
     {
         if(i%2==0)
         {
             int s=v[i][0];
             if(s%2==0)
                 return false;
             for(int j=1;j<v[i].size();j++)
             {
                 if(v[i][j]%2==0 || v[i][j]<=s)
                     return false;
                 s=v[i][j];
             }
         }
         else
         {
             int s=v[i][0];
             if(s%2)
                 return false;
             for(int j=1;j<v[i].size();j++)
             {
                 if(v[i][j]%2 || s<=v[i][j])
                     return false;
    s=v[i][j];             
             }
         }
     }
        return true;
    }
};*/


class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        bool flag=true;
      
        q.push(root);
        while(!q.empty()){
            int x = q.size() ;
            int prev = flag ? INT_MIN : INT_MAX;
            for(int i=0; i< x; i++){
                TreeNode* frontNode = q.front();
                q.pop();  
                if(flag){
                    if(frontNode->val %2==0 || frontNode->val <=  prev){
                     return false;
                    }
                }
                else{
                    if(frontNode->val %2!=0  || frontNode->val  >= prev){
            
                        return false;
                    }
                }

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                prev= frontNode->val;
            }
            flag=!flag;
        }
        return true;
    }
};