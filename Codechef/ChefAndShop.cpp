/*Chef likes shopping, and especially he likes to buy oranges. But right now he is short of money.
 He has only k rubles. There are n oranges. 
 The i-th one costs costi rubles and has weight equal to weighti. 
Chef wants to buy a set of oranges with the maximal possible weight.
 Please help him, and tell him this weight.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
high func(vector<pair<high,high>>&v,high k,high index,high wmax)
{
    if(index<0 || k<0)
    return wmax;
    else
    {
        high a=0,b=0;
        if(k>=v[index].first)
        {
            a=func(v,k-v[index].first,index-1,wmax+v[index].second);
        }
        b=func(v,k,index-1,wmax);
        return max(a,b);
    }
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n,k;
	    cin>>n>>k;
	    vector<pair<high,high>>v;
	    for(high i=0;i<n;i++)
	    {
	        high k,l;
	        cin>>k>>l;
	        v.push_back({k,l});
	    }
	    high val=func(v,k,n-1,0);
	    cout<<val<<endl;
	}
	return 0;
}