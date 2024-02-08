/*
Suppose you have an array B consisting of M non-negative integers.B is called good if you can make all elements of B equal to 0
by performing the following operation any (possibly 0) number of times:
Select two indices 
i and j (1≤i<j≤M);
Let X=Bi∣Bj, where ∣ denotes bitwise OR;
Replace Bi with X−Bi and Bj with X−Bj.
You are given integers N and K. Count number of arrays A of length N such that:0≤Ai<2^k A is good.
Since the number of arrays might be too large, please print it modulo 
998244353
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
long long int power(long long x, long long int y, int p) 
{ 
    long long int res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int main() {
	int t;
	cin>>t;
	int p=998244353;
	while(t--){
	    long long int n,k;
	    cin>>n>>k;
	    
	    long long int a1=power(2,n-1,p);
	    long long int a2=power(a1,k,p);
	    cout<<a2<<endl;
	}
	
	return 0;
}
