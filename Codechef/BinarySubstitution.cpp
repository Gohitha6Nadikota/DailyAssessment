/*
Chef has a binary string S. He can replace any occurrence of 01 with a 10 with b
010 with ab 101 with ba
While doing these operations, Chef noticed that he can end up with different strings depending upon the order of application 
of the operations. Given the final string containing only a and b,
Chef wants to know the number of possible strings he might have began with.

As the number of initial strings can be large, print the result modulo 998244353.
*/


#include <bits/stdc++.h>
using namespace std;
# define high long long 
#define MOD 998244353
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    vector<high>dp(s.size());
	    dp[0]=1;
	    dp[1]=dp[0]+(s[0]!=s[1]);
	    for(int i=2;i<s.size();i++)
	    {
	        if(s[i]!=s[i-1])
	            dp[i]=(dp[i-1]+dp[i-2])%MOD;
	        else
	            dp[i]=dp[i-1];
	    }
	    cout<<dp[s.size()-1]<<endl;
	}
	
	return 0;
}