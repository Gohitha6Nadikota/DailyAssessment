/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
*/


class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    
    void push(int x) 
    {
        s1.push(x);
    }
    bool empty()
    {
        if(s1.empty() && s2.empty())
            return true;
        else
            return false;
    }
    int pop() 
    {
       if(!s2.empty())
       {
           int val=s2.top();
           s2.pop();
           return val;
       }
       else
       {
           while(!s1.empty())
           {
               int val=s1.top();
               s1.pop();
               s2.push(val);
           }
           int val=s2.top();
           s2.pop();
           return val;
        }
    }
    
    int peek() 
    {
        if(!s2.empty())
        {
            int val=s2.top();
            return val;
        }
        else
        {
            while(!s1.empty())
            {
                int val=s1.top();
                s1.pop();
                s2.push(val);
            }
            int val=s2.top();
            return val;
        }
    }
    
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */