/*
Chef has a special interest in studying sets of integers.
Given an integer N, he defines a good-set as a set of distinct non-negative integers, such that:
The sum of the integers in the set is equal to N.
The product of each non-empty subset of the set is odd.
Determine the number of distinct sizes of good-set that can be formed.

2 0
3 1 {3}
4 1 {1,3}
5 1 {5}
6 1 {1,5}
7 1 {7}
8 1 {3,5} {1,7}
9  2 {1,3,5} {9}
10 1 {1,9}
11 2 {1,3,7} {11}
12 1 {1,11} {9,3} {7,5}
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
	    high n; cin>>n;
	    high x=sqrtl(n);
	    if((n-x*x)%2)
	    x--;
	    cout<<(x+1)/2<<endl;
	}
	return 0;
}


