/*
Given integers N and K, construct a permutation  of the integers {1,2,…,N} such that there are exactly 
K indices (1≤i<N) for which Pi+Pi+1 is odd.
It can be proved that the answer always exists under the constraint of 1≤K≤N−1.
If multiple answers exist, any of them will be accepted.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	high t; 
	cin>>t;
	//t=1;
	while(t--)
	{
	    high n,k;
	    cin>>n>>k;
	    if(k==n-1)
	    {
	        for(high i=1;i<=n;i+=1)
	        {
	            cout<<i<<" ";
	        }
	        cout<<endl;
	    }
	    else if(n%2==0)
	    {
    	    if(k%2==1)
    	    {
    	       vector<high>evens,odds;
    	       high i=0,j=0;
    	       for(high i=0;i<n;i++)
    	        {
    	            if((i+1)%2)
    	            odds.push_back(i+1);
    	            else
    	            evens.push_back(i+1);
    	       }
    	       high r=k/2;
    	            for(i=0;i<odds.size();i++)
    	            {
    	                cout<<odds[i]<<" ";
    	                if(r)
    	                {
    	                cout<<evens[j]<<" ";
    	                r--;
    	                j++;
    	                }
    	            }
    	            while(j<evens.size()){
    	            cout<<evens[j]<<" ";
    	            j++;
    	            }
    	            cout<<endl;
    	        }
    	        else
    	        {
    	            vector<high>evens,odds;
    	            high i=0,j=0;
    	            high r=(k-1)/2;
    	            for(high i=0;i<n-1;i++)
    	            {
    	            if((i+1)%2)
    	            odds.push_back(i+1);
    	            else
    	            evens.push_back(i+1);
    	            }
    	            cout<<n<<" ";
    	            for(i=0;i<odds.size();i++)
    	            {
    	                cout<<odds[i]<<" ";
    	                if(r)
    	                {
    	                cout<<evens[j]<<" ";
    	                r--;
    	                j++;
    	                }
    	            }
    	            while(j<evens.size()){
    	            cout<<evens[j]<<" ";
    	            j++;
    	            }
    	            cout<<endl;
    	        }
	    }
	    else
	    {
	        if(k%2==1)
    	    {
    	       vector<high>evens,odds;
    	       high i=0,j=0;
    	       for(high i=0;i<n;i++)
    	        {
    	            if((i+1)%2)
    	            odds.push_back(i+1);
    	            else
    	            evens.push_back(i+1);
    	       }
    	       high r=k/2;
    	            for(i=0;i<odds.size();i++)
    	            {
    	                cout<<odds[i]<<" ";
    	                if(r)
    	                {
    	                cout<<evens[j]<<" ";
    	                r--;
    	                j++;
    	                }
    	            }
    	            while(j<evens.size()){
    	            cout<<evens[j]<<" ";
    	            j++;
    	            }
    	            cout<<endl;
    	        }
    	        else
    	        {
    	            vector<high>evens,odds;
    	            high i=0,j=0;
    	            high r=(k-1)/2;
    	            for(high i=0;i<n-2;i++)
    	            {
    	            if((i+1)%2)
    	            odds.push_back(i+1);
    	            else
    	            evens.push_back(i+1);
    	            }
    	            odds.push_back(n);
    	            cout<<n-1<<" ";
    	            for(i=0;i<odds.size();i++)
    	            {
    	                cout<<odds[i]<<" ";
    	                if(r)
    	                {
    	                cout<<evens[j]<<" ";
    	                r--;
    	                j++;
    	                }
    	            }
    	            while(j<evens.size()){
    	            cout<<evens[j]<<" ";
    	            j++;
    	            }
    	            cout<<endl;
    	        }
	    }
	}
	return 0;
}
