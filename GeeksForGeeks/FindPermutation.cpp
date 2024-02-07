/*
You are given an array A of length 2*N consisting of exactly two occurrences of each integer from 1 to N.
Find a permutation P of length N, such that, for each 1≤i≤N:
If we delete both occurrences of Pj for all i<j≤N from A without changing the order of remaining elements, 
there will be atmost ∣A∣/2 elements between both occurrences of Pi in remaining A.
It is guaranteed that one such permutation always exists.
If multiple such permutations exist, you may print any.
Note that a permutation of length N consists of all integers from 1 to N exactly once.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
bool cmp(pair<high,high>&a,pair<high,high>&b)
{
    if(a.second>b.second)
    return true;
    return false;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n;
	    cin>>n;
	    vector<high>v;
	    vector<pair<high,high>>v1;
	    for(high i=0;i<2*n;i++)
	    {
	        high k;
	        cin>>k;
	        v.push_back(k);
	    }
	    map<high,high>index;
	    for(high i=0;i<2*n;i++)
	    {
	        if(index.find(v[i])!=index.end())
	        index[v[i]]=i;
	        else
	        index[v[i]]=abs(i-index[v[i]]);
	    }
	    for(auto x:index)
	    v1.push_back({x.first,x.second});
	    sort(v1.begin(),v1.end(),cmp);
	    for(auto x:v1)
	    cout<<x.first<<" ";
	    cout<<endl;
	}
	return 0;
}
