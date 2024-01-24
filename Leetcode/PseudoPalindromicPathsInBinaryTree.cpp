class Solution {
public:
    bool isPal(vector<int>v)
    {
        int ct=0;
        for(auto x: v)
        {
            if(x%2)
                ct+=1;
            if(ct>1)
                return false;
        }
        return true;
    }
    void func(TreeNode *root,vector<int>&v,int &c)
    {
       if(root==NULL)
           return;
        v[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            if(isPal(v))
                c+=1;
        }
        func(root->left,v,c);
        func(root->right,v,c);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int>ele(10,0);
        int c=0;
        func(root,ele,c);
        return c;
    }
};