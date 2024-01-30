/*
Tanish is the president of the chemistry club at his school.
 He considers everyone who doesn't like chemistry as his enemy. After years of research, he has invented a lethal poison,
  which he named success. Now Tanish plans to kill all his enemies with his success. 
Success is extremely deadly and is untraceable in small concentrations.
Tanish has N flasks lying on the shelf of his lab. All of these flasks contain the same volume of poison solution. 
The concentration of poison in the ith flask is ai.
In one move - Tanish picks up any two flasks, pours half of the contents of each of these flasks into a third initially
empty flask, discards the two flasks and places the third flask 
(which now has the same volume of solution as all other flasks) on the shelf. 
He performs N-1 such moves to end up with only one flask of poison on the shelf. 
He wishes to perform these moves such that the concentration of poison in this flask is the minimum possible. 
What is the minimum concentration of poison that he can achieve?
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
	    vector<double>a;
	    for(high i=0;i<n;i++)
	    {
	        double k;
	        cin>>k;
	        a.push_back(k);
	    }
	    sort(a.begin(),a.end());
	    double d=(a[n-1]+a[n-2])/2;
	     for(high i=n-3;i>=0;i--)
	     {
	       d=(d+a[i])/2;
	      
	       
	    }
	    cout<<fixed<<setprecision(8)<<d<<endl;
	}
	return 0;
}
