/*
Given an integer N, generate a matrix A of size N×N such that:
A (i,j) is distinct and A (i,j)∈[1,N^2];
The boundary sum of all square sub-matrices starting from 
A (1,1) is odd.
For example, in a matrix 
A of size 3×3, the following sums should be odd:
A(1,1)
A (1,1)+A(1,2)+A(2,1)+A (2,2)
A(1,1)+A(1,2)+A(1,3)+A(2,1)+A (2,2)+A(2,3)+A(3,1)+A(3,2)+A(3,3)
If no such matrix exists, print −1.
If multiple such matrices exist, you may print any.
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
	    high n; cin>>n;
	    if(n==1)
	    cout<<1<<endl;
	    else if(n==2)
	    cout<<-1<<endl;
	    else
	    {
	        vector<vector<int>>mat(n,vector<int>(n,0));
	        stack<int> odds,evens;
            for (int i = 1; i <= n*n; i++) 
            {
                if (i&1) odds.push(i);
                else evens.push(i);
            }
	        bool check = false;
            for (int i = 0; i < n; i++)
            {
                int count = 0;
            for (int j = 0; j <= i; j++) 
            {
                if (!odds.empty())
                {
                    mat[i][j]=odds.top();
                    odds.pop();
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (i==n-1 && (i+count)%2==0)
            {
                check = true;
            }
        }
        if (check)
        {
            mat[0][n-2] = mat[n-2][n-2];
            mat[n-2][n-2] = 0;
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j]==0)
                {
                    mat[i][j] = evens.top();
                    evens.pop();
                }
            }
        }
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                cout<<mat[i][j]<<" ";
	            }
	            cout<<endl;
	        }
	    }
	}
	return 0;
}


/*
Filling the upper matrix with all odds and satisifying the condition and then filling the evens


*/
