/*
Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.
*/

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int c=1;
        for(int i=2;i<sqrt(2*n);i++)
            if((n-(i*(i-1))/2)%i==0)
                c++;

        return c;
    }
};




/*
let the number be x,x+1,x+2,....x+k then
k*x + k*(k-1)/2 =n
hence 

k*x= n - k*(k-1)/2

so x= ( n - k*(k-1)/2)/k

in the worst case the value will be x>0
n-k*(k-1)/2 > 0
k*k - k < 2n
k*k < 2n
k < sqrt(2n)
*/