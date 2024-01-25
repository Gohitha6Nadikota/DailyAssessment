/*
[This problem is very similar to XORRY1.
 The only difference is that instead of printing any one Xorry pair, you are now asked to count the number of Xorry pairs]
You are given an integer X. Two integers (A,B) are said to be an Xorry pair, 
if the following conditions are satisfied:A⊕B=X
0≤A≤B≤X
Among all the pairs which satisfy the above two conditions, (B−A) is as small as possible
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
	   high k=n;
	   string c="";
	   while(k)
	   {
	       if(k%2)
	       c='1'+c;
	       else
	       c='0'+c;
	       k=k/2;
	    }
	    high c1=0;
	    high cones=0;
	    high i;
    	for(high i=0;i<c.size();i++)
    	{
    	   if(c[i]=='1')
    	   cones++;
    	   if(cones>=2 && c[i]=='0')
    	   c1++;
    	}
	    cout<<(1<<c1);
	   cout<<endl;
	}
	return 0;
}


/*
Xorry1

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
high func(high n)
{
    high v=1;
    if(n==1)
    return 1;
    while(v*2<=n)
    {
        v=v*2;
    }
    return v;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n;
	    cin>>n;
	    high c=func(n);
	    high d=n-c;
	    cout<<min(c,d)<<" "<<max(c,d)<<endl;
	}
	return 0;
}

*/