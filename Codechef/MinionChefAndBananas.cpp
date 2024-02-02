/*
Minion Chef likes to eat bananas a lot. There are N piles of bananas in front of Chef; for each i (1 ≤ i ≤ N), 
the i-th pile contains Ai bananas.

Chef's mother wants her to eat the bananas and be healthy. She has gone to the office right now and will come back in H hours. 
Chef would like to make sure that she can finish eating all bananas by that time.

Suppose Chef has an eating speed of K bananas per hour. Each hour, she will choose some pile of bananas. 
If this pile contains at least K bananas, then she will eat K bananas from it. Otherwise, she will simply eat the whole pile 
(and won't eat any more bananas during this hour).

Chef likes to eat slowly, but still wants to finish eating all the bananas on time. 
Therefore, she would like to choose the minimum K such that she is able to eat all the bananas in H hours. 
Help Chef find that value of K.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
bool canEat(high n,high h,vector<high>&nums)
{
    high c=0;
    for(auto x: nums)
    {
        c+=x/n;
        if(x%n)
        c++;
    }
    return c<=h;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    high n,h;
	    cin>>n>>h;
	    vector<high>v;
	    for(high i=0;i<n;i++)
	    {
	        high k; 
	        cin>>k;
	        v.push_back(k);
	    }
	    high start=1,end=1000000000;
	    while(start<=end)
	    {
	        high mid=start+(end-start)/2;
	        if(canEat(mid,h,v))
	        {
	            end=mid-1;
	        }
	        else
	        {
	            start=mid+1;
	        }
	    }
	    cout<<start<<endl;
	}
	return 0;
}
