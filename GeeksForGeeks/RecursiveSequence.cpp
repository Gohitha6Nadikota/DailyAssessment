/*
A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). 
Given an integer n, determine the F(n).

Note: As the answer can be very large, return the answer modulo 109+7.
*/


class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        long long c=1;
        for(int i=1;i<=n;i++)
        {
            long long product=1;
            for(int j=1;j<=i;j++)
            {
                product=(product*c)%1000000007;
                c++;
            }
            ans=(ans+product)%1000000007; 
        }
        return ans;
    }
};