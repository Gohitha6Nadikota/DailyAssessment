/*
Alexandra has some distinct integer numbers a1,a2...an. 
Count number of pairs (i,j) such that:
1≤ i ≤ n 
1≤ j ≤ n 
ai < aj
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
	    high c=n*(n-1)/2;
	    cout<<c<<endl;
	    
	}
	return 0;
}
