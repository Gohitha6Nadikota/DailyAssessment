/*
You are given two linked lists that represent two large positive numbers. 
From the two numbers represented by the linked lists, subtract the smaller number from the larger one.
Look at the examples to get a better understanding of the task.
*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* lrev(Node *head)
    {
        Node* curr=head,*nxt=head;
        Node* prev=nullptr;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        if(!head1 && !head2)
        return new Node(0);
        else if(head1 && !head2)
        return head1;
        else if(!head1 && head2)
        return head2;
        while(head1 && head1->data==0)
        head1=head1->next;
        while(head2 && head2->data==0)
        head2=head2->next;
        int c1=0,c2=0;
        Node* h=head1;
        while(h)
        {
            c1++;
            h=h->next;
        }
        h=head2;
        while(h)
        {
            c2++;
            h=h->next;
        }
        if(c2>c1)
        {
            Node* h1=head1;
            head1=head2;
            head2=h1;
        }
        else if(c1==c2)
        {
            while(head1 && head2 && head1->data==head2->data)
            {
                head1=head1->next;
                head2=head2->next;
            }
            if(!head1 && !head2)
            return new Node(0);
            if(head1->data<head2->data)
            {
                Node* h1=head1;
                head1=head2;
                head2=h1;
            }
        }
        head1=lrev(head1);
        head2=lrev(head2);
        int carry=0;
        Node * s=new Node(-1);
        Node * t=s;
        while(head2)
        {
            int val=head1->data-(head2->data+carry);
            carry=0;
            if(val<0)
            {
                carry=1;
                val+=10;
            }
            Node * n=new Node(val);
            t->next=n;
            t=t->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(carry)
        {
            int val=head1->data-carry;
            carry=0;
            if(val<0)
            {
                carry=1;
                val+=10;
            }
            Node * n=new Node(val);
            t->next=n;
            t=t->next;
            head1=head1->next;
        }
        t->next=head1;
        Node * h2=lrev(s->next);
        while(h2 && h2->data==0)
        h2=h2->next;
        if(h2)
        return h2;
        else
        return new Node(0);
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends