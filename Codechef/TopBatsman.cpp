/*
A cricket team consists of 11 players and some are good at batting, 
others are good at bowling and some of them are good at both batting and bowling. 
The batting coach wants to select exactly K players having maximum possible sum of scores. 
Given the batting score of each of the 11 players, 
find the number of ways in which we can select exactly K players such that the sum of their scores is the maximum possible. 
Two ways are different if there is a player who is selected in one of them is not in the other.
 See explanation of sample cases for more clarity.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
int fact(int n)
{
    int s=1;
    for(int t=2;t<=n;t++ )
    {
        s=s*t;
    }
    return s;
}
int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    int arr[11];
        int temp=0;
        int c=0;int d=0;
        for(int i=0;i<11;i++)
        {
            cin >> arr[i];
        }
        int n;
        cin >> n;
        for(int i=0;i<11;i++)
        {
            for(int j=i;j<11;j++)
            {
                if(arr[j]>arr[i])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        for(int i=0;i<11;i++)
	   {
	       if(arr[i]==arr[n] && i<n)
	       {
	           d++;
	       }
	      if(arr[i]==arr[n])
	      {
	          c++;
	      }
	   }
	   int m=fact(c)/(fact(d)*fact(c-d));
	   cout << m << endl;
	   
        
	}
	return 0;
}
