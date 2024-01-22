/*
Given a Binary tree and a sum S, 
print all the paths, starting from root, that sums upto the given sum. Path not necessarily end on a leaf node.
*/

//User function Template for C++

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    void func(Node *root,int &sum,vector<vector<int>>&ans,int tot,vector<int>&arr)
    {
        if(root==NULL)
        return;
        if(tot==sum)
        {
            ans.push_back(arr);
            if(root->left)
            {
            arr.push_back(root->left->key);
            func(root->left,sum,ans,tot+root->left->key,arr);
            arr.pop_back();
            }
            if(root->right)
            {
            arr.push_back(root->right->key);
            func(root->right,sum,ans,tot+root->right->key,arr);
            arr.pop_back();
            }
        }
        else
        {
            if(root->left)
            {
                arr.push_back(root->left->key);
                func(root->left,sum,ans,tot+root->left->key,arr);
                arr.pop_back();
            }
            if(root->right)
            {
                arr.push_back(root->right->key);
                func(root->right,sum,ans,tot+root->right->key,arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>>ans;
        vector<int>v;
        v.push_back(root->key);
        func(root,sum,ans,root->key,v);
        return ans;
    }
};