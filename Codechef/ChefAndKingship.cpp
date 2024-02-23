/*
Chef is the new king of the country Chefland. 
As first and most important responsibility he wants to reconstruct the road system of Chefland. 
There are N (1 to N) cities in the country and each city i has a population Pi.
Chef wants to build some bi-directional roads connecting different cities such that each city is connected to every other city
(by a direct road or through some other intermediate city) and 
starting from any city one can visit every other city in the country through these roads. 
Cost of building a road between two cities u and v is Pu x Pv. 
Cost to build the road system is the sum of cost of every individual road that would be built.

Help king Chef to find the minimum cost to build the new road system in Chefland such that every city is connected to each other.
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
	    high p[n];
	    high cost=0;
	    for(auto i=0;i<n;i++)
	     cin>>p[i];
	    
	    sort(p,p+n);
	   for(high i=1;i<n;i++)
	   {
	       cost=cost+p[0]*p[i];
	   }
	    cout<<cost<<endl;
	}
	return 0;
}
