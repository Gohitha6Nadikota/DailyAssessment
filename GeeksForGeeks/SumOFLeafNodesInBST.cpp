/*
Given a Binary Search Tree with n nodes, find the sum of all leaf nodes. 
BST has the following property (duplicate nodes are possible):

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Your task is to determine the total sum of the values of the leaf nodes.

Note: Input array arr doesn't represent the actual BST, 
it represents the order in which the elements will be added into the BST.
*/


//{ Driver Code Starts
//Author- SAJAL AGRAWAL
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *insert(Node *r,int num);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);


// } Driver Code Ends
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    public:
        /*You are required to complete below method */
        int sum=0;
        void func(Node *root)
        {
            if(root->left==NULL && root->right==NULL)
            {
                sum+=root->data;
            }
            if(root->left)
            {
                func(root->left);
            }
            if(root->right)
            {
                func(root->right);
            }
            return;
        }
        int sumOfLeafNodes(Node *root )
        {
             /*Your code here */
             func(root);
             return sum;
        }
};

//{ Driver Code Starts.

int main(void) {
    int t,n,data;
    scanf("%d",&t);
    while(t--){
        Node *root=NULL;
        scanf("%d",&n);
        //printf("n=%d\n",n);
        while(n--){
            scanf("%d",&data);
            //printf("data=%d\n",data);
            root=insert(root,data);
        }
        //inOrderDisplay(root);
        Solution obj;
        printf("%d\n",obj.sumOfLeafNodes(root));
    }
	return 0;
}

Node *insert(Node *r,int num){
    if(r==NULL){
        r = new Node(num);
    }else{
        if(num<r->data){
            r->left=insert(r->left,num);
        }else{
            r->right=insert(r->right,num);
        }
    }
    return r;
}

void preOrderDisplay(Node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node *r){
    if(r!=NULL){
        inOrderDisplay(r->left);
        printf("%d ",r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node *r){
    if(r!=NULL){
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ",r->data);
    }
}

int search(Node *r,int num){
    if(r==NULL)return 0;
    else if(r->data==num)return 0;
    else if(r->data > num)
        search(r->left,num);
    else 
        search(r->right,num);
}
// } Driver Code Ends