/*
There are N friends numbered 1 to N, seated in a straight line where the 
i th seat is taken by friend numbered Ai
This Christmas, the friends have decided to distribute candies amongst each other.
For each 1≤i<N, the friend at the i th seat will gift one candy to the friend at the jth seat if:
j>i
A j<A i
Find the number of people who receive at least one candy.
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
	    vector<high>v;
	    for(high i=0;i<n;i++)
	    {
	        high k;
	        cin>>k;
	        v.push_back(k);
	    }
	    high mx=v[0];
	    high c=0;
	    for(high i=0;i<n;i++)
	    {
	        if(mx<=v[i])
	        mx=v[i];
	        else
	        c++;
	    }
	    cout<<c<<endl;
	}
	return 0;
}
