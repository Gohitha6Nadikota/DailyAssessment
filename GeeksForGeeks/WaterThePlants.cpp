/*
    A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. 
    There are provisions for attaching water sprinklers in every division.
     A sprinkler with range x at division i can water all divisions from i-x to i+x.

    Given an array gallery[] consisting of n integers, 
    where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached),
    return the minimum number of sprinklers that need to be turned on to water the entire gallery. 
    If there is no possible way to water the full length using the given sprinklers, print -1.
*/

/*class Solution:
    def min_sprinklers(self, g, n):
        # code here
        l=[]
        for i in range(n):
            if g[i]!=-1:
                l.append((i-g[i],i+g[i]))
        l=sorted(l)
        i,r,c=0,0,0
        while r<n:
            if i==len(l) or r<l[i][0]:
                return -1
            rmax=l[i][1]
            while i+1<len(l) and l[i+1][0]<=r :
                i+=1
                rmax=max(rmax,l[i][1])
            if rmax<r:
                return -1
            c+=1
            r=rmax+1
            i+=1
        return c
*/

//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<vector<int>>boundaries;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            {
                boundaries.push_back({i-gallery[i],i+gallery[i]});  //ranges each pipe covers
            }
        }
        sort(boundaries.begin(),boundaries.end()); // greedy approach
        int right=0,i=0,ans=0;
        while(right<n)
        {
            if(i==n || right<boundaries[i][0])
            return -1;
            int presentright=boundaries[i][1];
            while(i+1<n && boundaries[i+1][0]<=right)
            {
                i+=1;
                presentright=max(presentright,boundaries[i][1]);
            }
            if(presentright<right)
            return -1;
            ans++;
            right=presentright+1;
            i+=1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends

