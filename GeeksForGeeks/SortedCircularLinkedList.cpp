/*
Given a sorted circular linked list of length n,
 the task is to insert a new node in this circular list 
 so that it remains a sorted circular linked list.
*/

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node* current = head; 
        Node* new_node=new Node(data);
        if (current == NULL) 
        { 
            new_node->next = new_node; 
            head = new_node; 
  
        } 
        else if (current->data >= new_node->data) 
        { 
  
            while (current->next != head) 
                current = current->next; 
  
            current->next = new_node; 
            new_node->next = head; 
            head = new_node; 
        } 
        else
        { 
            while (current->next != head && current->next->data < new_node->data) 
                current = current->next; 
  
            new_node->next = current->next; 
            current->next = new_node; 
        } 
        return head;
       
    }
};