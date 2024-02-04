/*
Chefina has an array A consisting of N non-negative integers.
The beauty of a subsequence S is defined as 3*abs(means(S) - median(S)),where 
mean(S)
mean(S) denotes the mean of subsequence S and 
median(S)
median(S) denotes the median of subsequence S.

Now, Chefina asks Chef to choose a subsequence S of size 3 from array A such that the beauty of S is minimised. 
Your task is to find the minimum beauty possible.
As a reminder, a subsequence of an array is obtained by deleting some elements from the array without changing 
the order of the remaining elements.

Note: It can be proven that the answer is always an integer.
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<long long>&A,int start,int end,long long req)
{
    
    int ans = A.size()-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(A[mid]>=req)
        {
            ans = min(ans,mid);
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
} 

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    vector<long long> A(n);
	    
	    for(int i=0;i<n;++i)
	    {
	        cin>>A[i];
	    }
	    sort(A.begin(),A.end());
	    
	    long long ans = 1e18;
	    long long req,cur,score;
	    
	    for(int i=0;i<(n-2);++i)
	    {
	        for(int j=i+1;j<(n-1);++j)
	        {
	            req = 2ll*A[j] - A[i];
	            int idx = search(A,j+1,n-1,req);
	            cur = A[idx];
	            score = abs(cur - req);
	            ans = min(ans,score);
	            if(idx>(j+1))
	            {
	                idx--;
	            }
	            cur = A[idx];
	            score = abs(cur - req);
	            ans = min(ans,score);
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
