/*
Chef has an array A of length N.
An index i is called strong if we can change the gcd of the whole array just by changing the value of Ai.
Determine the number of strong indices in the array.
*/

#include <bits/stdc++.h>
#define h long long
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin>>k;
	        v.push_back(k);
	    }
	    vector<int>b,a;
	    int f=v[0];
	    //b.push_back(v[0]);
	    for(int i=0;i<n;i++){
	       b.push_back(__gcd(f,v[i]));
	       f=__gcd(f,v[i]);
	    } 
	    //a.push_back(v[n-1]);
	    f=v[n-1];
	    for(int i=n-1;i>=0;i--){
	        a.push_back(__gcd(f,v[i]));
	    
	        f=__gcd(f,v[i]);
	    }
	    reverse(a.begin(),a.end());
	   int count=0;
	   for(int i=1;i<n-1;i++)
	   {
	       if(__gcd(b[i-1],a[i+1])!=1)
	           count++;
	   }
	   if(b[n-2]!=1)
	   count++;
	   if(a[1]!=1)
	   count++;
	   
	   cout<<count<<endl;
	}
	return 0;
}
