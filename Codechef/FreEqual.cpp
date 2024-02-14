/*
An array A of length N is called frequal if, for each i (1≤i≤N), the frequency of A i
equals the number of its positive divisors.
For example, 
[2,8,1,8,8,8,2] is a frequal array (
1
1 has one divisor, 
2
2 has two divisors, and 
8
8 has four divisors)
10 has four divisors but appears only three times in the array).
Let f(A) denote the number of distinct elements in A.
For instance, f([1,1,1,1])=1, and f([1,3,2,9,2,9,1])=4.
You are given an integer N.
Find any frequal array A of length N such that f(A) is as large as possible.
The array should satisfy 
It can be shown that such a frequal array always exists.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	vector<high>v(1000001,1),v1;
    v[1]=0;
    for(high i=2;i*i<=1000001;i++)
    {
        if(v[i]==1)
        {
            for(high j=i*i;j<=1000001;j+=i)
            {
                v[j]=0;
            }
        }
    }
    for(high i=1;i<1000001;i++)
    {
        if(v[i])
        v1.push_back(i);
    }
	high t; 
	cin>>t;
	while(t--)
	{
	    high n;
	    cin>>n;
	    if(n%2==1)
	    {
	        cout<<1<<" ";
	        n--;
	    }
	    for(high i=0;i<n/2;i++)
	    cout<<v1[i]<<" "<<v1[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
