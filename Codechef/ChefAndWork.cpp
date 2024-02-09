/*
Chef has N small boxes arranged on a line from 1 to N. For each valid i, the weight of the i-th box is Wi.
 Chef wants to bring them to his home, which is at the position 0.
 He can hold any number of boxes at the same time; however, the total weight of the boxes 
 he's holding must not exceed K at any time, and he can only pick the ith box if all the boxes between Chef's 
 home and the ith box have been either moved or picked up in this trip.

Therefore, Chef will pick up boxes and carry them home in one or more round trips. 
Find the smallest number of round trips he needs or determine that he cannot bring all boxes home.
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
	    high n,k;
	    cin>>n>>k;
	    high arr[n];
	    high mx=INT_MIN;
	    for(high i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        mx=max(mx,arr[i]);
	    }
	    if(mx>k)
	    cout<<-1<<endl;
	    else
	    {
	        high trip=0;
	        high i=0;
	        while(1)
	        {
	            high sum=0;
	            while(sum+arr[i]<=k)
	            {
	                sum+=arr[i];
	                i++;
	            }
	            trip++;
	            if(i>=n)
	            {
	                cout<<trip<<endl;
	                break;
	            }
	        }
	    }
	}
	return 0;
}
