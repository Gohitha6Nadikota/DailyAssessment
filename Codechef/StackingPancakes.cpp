/*
Chef is good at making pancakes. Generally he gets requests to serve N pancakes at once.
He serves them in the form of a stack. A pancake can be treated as a circular disk with some radius.
Chef needs to take care that when he places a pancake on the top of the stack the radius of the pancake 
should not exceed the radius of the largest pancake in the stack by more than 1. 
Additionally all radii should be positive integers, and the bottom most pancake should have its radius as 1. 
Chef wants you to find out in how many ways can he create a stack containing N pancakes.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	high t; 
	cin>>t;
	vector<vector<int>>dp(1001,vector<int>(1001,0));
	vector<int>ans;
	ans.push_back(0);
	dp[1][1]=1;
	ans.push_back(1);
	for(high i=2;i<1001;i++)
	{
	    high c=0;
	    for(high j=1;j<i+1;j++)
	    {
	        dp[i][j]=dp[i-1][j-1]+((dp[i-1][j]*j)%mod);
	        dp[i][j]%=mod;
	        c+=dp[i][j];
	        c%=mod;
	    }
	    ans.push_back(c);

        // dp[i-1][j-1] indicating that the max radius till placed is j-1 and j can be placed now
        // dp[i-1][j] * j indicating that the max radius till placed is j and can place all other smaller sizes upon the jth one
	}
	while(t--)
	{
	    high n;
	    cin>>n;
	    cout<<ans[n]<<endl;
	    
	}
	return 0;
}
