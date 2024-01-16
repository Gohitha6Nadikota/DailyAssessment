/*
    You are given two integer arrays A and B each of size N. 
Let us define interaction of arrays A and B to be the sum of A[i] * B[i] for each i from 1 to N.
You want to maximize the value of interaction of the arrays. 
You are allowed to make at most K (possibly zero) operations of following kind.
In a single operation, you can increase or decrease any of the elements of array A by 1.
Find out the maximum value of interaction of the arrays that you can get.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	high t; 
	cin>>t;
	while(t--)
	{
	    high n,k;
	    cin>>n>>k;
	    vector<high>a,b;
	    high sum=0;
	    for(high i=0;i<n;i++)
	    {
	        high k; cin>>k;
	        a.push_back(k);
	    }
	    for(high i=0;i<n;i++)
	    {
	        high k; cin>>k;
	        b.push_back(k);
	    }
	    for(high i=0;i<n;i++)
	    sum+=a[i]*b[i];
	    
	    high mx=sum;
	    for(int i=0;i<n;i++) // check for all the possibilities
	    {
	        if(b[i]<0)
	        mx=max(mx,sum-(a[i]*b[i])+((a[i]-k)*b[i])); // if one value is negative subtract k times or else add k times
	        else
	        mx=max(mx,sum-(a[i]*b[i])+(a[i]+k)*b[i]);
	    }
	    cout<<mx<<endl; //  choose the best one
	}
	return 0;
}
