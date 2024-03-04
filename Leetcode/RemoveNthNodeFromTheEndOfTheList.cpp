/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode * h=head;
        ListNode *f=head;
        ListNode *s=head;
        while(n--)
        {
            f=f->next;
        }
        if(f==NULL)
            return h->next;
        while(f->next)
        {
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return h;
    }
};