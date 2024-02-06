/*
Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and 
leaf is exactly k.

Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes,
 then it would add only 1 to our count.
*/

//Node Structure
/*struct Node
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    
    void dfs(Node *root,vector<Node *>&v,int k,set<Node*>&s)
    {
        v.push_back(root);
        if(root->left==NULL && root->right==NULL)
        {
            int n=v.size();
            if(n>=k+1)
            s.insert(v[n-k-1]);
        }
        if(root->left)
        {
            dfs(root->left,v,k,s);
            v.pop_back();
        }
        if(root->right)
        {
            dfs(root->right,v,k,s);
            v.pop_back();
        }
        
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here.
    	vector<Node*>v;
    	set<Node*>s;
    	if(!root)
    	return 0;
    	else
    	dfs(root,v,k,s);
    	return s.size();
    }
};
