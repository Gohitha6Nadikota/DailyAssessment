/*
Chef is participating in a pogo stick race. In this competition, there are N squares (numbered 1 through N) in a row.
Chef must choose a starting square, enter this square and start jumping on his pogo stick. 
In each jump, if Chef is at a square s, then he can only jump to the square s+K.
If square s+K does not exist, Chef jumps out of the row of squares and the race ends for him. 
It is not allowed to stop jumping any earlier.

Each square has a value; let's denote the value of the i-th square by Ai.
Initially, Chef has 0 points. W
Then he jumps in some square (including the initial square), 
 he is awarded a number of points equal to the value of this square, exactly once.
Note that if this value is negative, the number of Chef's points is decreased.

Determine the maximum possible total number of points Chef can get if he selects the initial cell optimally.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n,k;
	    cin>>n>>k;
	    high arr[n];
	    for(high i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    high ans=arr[n-1];
	    for(high i=n-1;i>=0;i--)
	    {
	        if(i+k<n)
	        arr[i]+=arr[i+k];
	        ans=max(ans,arr[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
