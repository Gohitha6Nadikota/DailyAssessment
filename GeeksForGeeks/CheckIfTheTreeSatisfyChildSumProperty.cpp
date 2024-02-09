/*
Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes.
Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. 
Consider data value as 
*/


/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
       if(root==NULL || root->left==NULL && root->right==NULL)
       return 1;
       int sum=0;
       if(root->left)
       {
          sum+=root->left->data;
       }
        if(root->right)
       {
          sum+=root->right->data;
       }
       return root->data==sum && isSumProperty(root->left) && isSumProperty(root->right);
       
       
    }
};