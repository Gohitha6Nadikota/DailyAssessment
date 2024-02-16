/*
There are N minions who are competing in an election of the president of the ACM (Association of Cute Minions).
 They are standing in a line in the order from minion 1 to minion N. 
 For each i (1 ≤ i ≤ N), the i-th minion has an influence level of Si.

A single minion may cast any number of votes. Minion j will vote for minion i (i ≠ j) 
if and only if the influence level of the j-th minion is greater than or equal to the sum of influence levels of all
 the minions standing between them (excluding the i-th and j-th minion).

Your task is to find the number of votes received by each minion.
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
	    high n;
	    cin>>n;
	    high arr[n],sum[n],votes[n];
	    high s=0;
	    for(high i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        votes[i]=0;
	        s+=arr[i];
	        sum[i]=s;
	    }
	    for(high i=0;i<n;i++)
	    {
	        for(high j=i-1;j>=0;j--)
	        {
	            if(arr[i]>=(sum[i-1]-sum[j]))
	            votes[j]+=1;
	            else
	            break;
	        }
	        for(high j=i+1;j<n;j++)
	        {
	            if(arr[i]>=(sum[j-1]-sum[i]))
	            votes[j]+=1;
	            else
	            break;
	        }
	    }
	    for(high i=0;i<n;i++)
	    {
	        cout<<votes[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
