/*
Ayush is being interviewed for an executive role in the finance department of Aparoksha, IIIT Allahabad's annual tech fest.
Himanshu Shekhar, the interviewer, decided to test Ayush's mathematical skills with the following problem.
An integer is called good if, when written in binary, it doesn't contain 101 as a subsequence.
Note that a subsequence need not be contiguous.

Ayush is given an integer N. He can do the following operation on it:
Choose an integer x≥0, and add 2^x to N.
The cost of this operation is 2^x.
Ayush's task is to find the minimum total cost needed to transform N into a good integer.
Can you help him find this minimum cost?
The total cost of a sequence of moves is the sum of their individual costs.

It can be shown that it's always possible to transform N into a good integer.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
string func(high n)
{
    string s="";
    while(n)
    {
        if(n&1)
        s+='1';
        else
        s+='0';
        n=n>>1;
    }
    return s;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n;
	    cin>>n;
	    string a=func(n);
	    high sum=0;
	    high val=0;
	    high i=0,n1=a.size();
	    while(i<n1)
	    {
	        if(a[i]=='1')
	        break;
	        i++;
	    }
	    while(i<n1)
	    {
	        if(a[i]=='0')
	        {
	            a[i]=1;
	            sum+=val;
	            val=1<<i;
	        }
	        else
	        {
	            if(val==0)
	            val=1<<i;
	            else
	            i++;
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
