/*
On the occasion of International Education Day, a fair is held in Chefland.
Both Chef and Chefina have set up their stalls.
Chef sells each item at his stall for A rupees and Chefina sells each item at her store for B rupees.
If both of them sell exactly C items, find the maximum amount in sales amongst Chef and Chefina.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	int a,b,c ;
	cin>> a;
	cin>> b;
	cin>> c;
	int d = a*c ;
	int e = b*c ;
	
	if (d>e){
	    cout << d;
	}
	else
	{
	    cout << e ;
	}
	
	return 0;
}
