/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>s;
        for(auto x: t)
        {
            if(x=="+")
            {
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(x=="-")
            {
                int b=s.top();

                s.pop();

                int a=s.top();

                s.pop();

                s.push(a-b);
            }
            else if(x=="*")
            {
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                s.push(a*b);
            }
            else if(x=="/")
            {
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                s.push(a/b);
            }
            else
            {
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};