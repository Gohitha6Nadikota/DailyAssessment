/*
    You had an array of integer numbers. 
    You also had a beautiful operations called "Copy-Paste" which 
    allowed you to copy any contiguous subsequence of your array and paste it in any position of your array.
     For example, if you have array [1, 2, 3, 4, 5] and 
     copy it's subsequence from the second to the fourth element and paste it after the third one,
      then you will get [1, 2, 3, 2, 3, 4, 4, 5] array. 
      You remember that you have done a finite(probably zero) number of such operations over your initial array and
       got an array A as a result. 
       Unfortunately you don't remember the initial array itself, 
       so you would like to know what could it be. 
       You are interested by the smallest such array. 
    So the task is to find the minimal size(length) of the array that A can be obtained from by using "Copy-Paste" operations
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
        set<high>s;
        for(high i=0;i<n;i++)
        {
            high a; cin>>a;
            s.insert(a);
        }
        high cnt= s.size();
        cout<<cnt<<endl;
	}
	return 0;
}
