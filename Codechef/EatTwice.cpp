/*
Hasan has recently heard about Chef's restaurant, which serves the tastiest dishes. The restaurant has published a list of N dishes (numbered 
1 through N that will be served in the next M days. For each valid i, the i-th dish will be served only on the 
i-th day. Hasan has investigated their tastiness and he knows that for each valid i-th dish has tastiness vi.
Hasan's budget is only large enough to try two dishes. He wants to choose these two dishes in such a way that their total (summed up) tastiness is as large as possible.
However, he cannot try 2 dishes on the same day.
Help Hasan and calculate the maximum possible total tastiness of the dishes he should try.
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
	    high n,m;
	    cin>>n>>m;
	    map<high,high>mp;
	for(int i=0; i<n; i++)
	{
	    high x,y;
		cin>>x>>y;
		mp[x]=max(mp[x], y);
	}
	vector<high>v;
	for(auto x:mp){
        v.push_back(x.second);
    }
	sort(v.begin(), v.end(), greater<int>());
	cout<<v[0]+v[1]<<endl;
	}
	return 0;
}
