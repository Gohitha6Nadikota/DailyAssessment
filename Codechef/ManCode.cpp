/*
n Chefland, it is illegal for two people to use adjacent urinals at the same time (as it should be).
It is also obviously illegal for them to use the same urinal at the same time (as it definitely should be).

There are N urinals in a row in Chefland.
Find both the maximum and the minimum number of people that can use these N urinals simultaneously, 
such that there is no place for another person to join.
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
	    cout<< n/2 + (n%2?1:0)<<" "<< n/3 + (n%3?1:0) <<endl;
	}
	return 0;
}
