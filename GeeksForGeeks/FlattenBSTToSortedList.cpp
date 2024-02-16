/*
You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. 
The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), 
and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity).
 You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

*/


//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
Node *head=NULL,*tail=NULL;
    void func(Node *root)
    {
        if(root==NULL)
        return;
        func(root->left);
        if(!head)
        {
           head= new Node(root->data);
           tail=head;
        }
        else
        {
            
            tail->right=new Node(root->data);
    
            tail=tail->right;
        }
        func(root->right);
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
       func(root);
       return head;
    }
};