/*
n this problem we assume, that Harrenhal can be described as a string H, which consists only of symbols 'a' and 'b'.
 Harrenhal is completely ruined if and only if the length of H is equal to zero.

So, how to make H empty? Send a military troop! When a military troop of the king reach the castle, 
they delete some palindromic subsequence S of H. For example, let H = 'abbabaab'. 
Then the current military troop can choose S = 'ababa'(Let's make symbols of S bold in H: 'abbabaab'). 
After deleting S, H will be equal to 'bab'. Military troops are free to choose any possible palindromic subsequence of H.

Your task is pretty simple: determine the minimal number of military troops, 
that the Lord of the Seven Kingdoms has to send in order to ruin Harrenhal.
*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
bool isPalindrome(string s,high l)
{
    for(int i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-i-1])
        return false;
    }
    return true;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    high l=s.length();
	    if(isPalindrome(s,l))
	    cout<<1;
	    else
	    cout<<2;
	    cout<<endl;
	}
	return 0;
}

