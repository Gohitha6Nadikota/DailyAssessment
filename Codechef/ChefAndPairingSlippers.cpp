/*
Chef has N slippers, L of which are left slippers and the rest are right slippers.
Slippers must always be sold in pairs, where each pair contains one left and one right slipper. 
If each pair of slippers cost X rupees, what is the maximum amount of rupees that Chef can get for these slippers?
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
	    int N,L,X,R;
	    cin>>N>>L>>X;
	    R = N - L;
	    if(R < L) {
	        cout<<R*X<<endl;
	    } else {
	        cout<<L*X<<endl;
	    }
	}
	return 0;
}
