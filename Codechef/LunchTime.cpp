/*
There are N students standing in a canteen queue, numbered1 to N from left to right.
 For each valid i, the i-th student has a height hi
Two students i and j can see each other if there are no taller students standing between them. Formally, students
(i<j) can see each other if for each integer
i<k<j . For each valid i, determine the numberci of students that have the same height as student i and can be seen by student i.
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
	    high n;
	    cin>>n;
	    vector<high>v;
	    for(high i=0;i<n;i++)
	    {
	        high k;
	        cin>>k;
	        v.push_back(k);
	    }
	    for(high i=0;i<n;i++)
	    {
	        high c=0;
	        for(int j=i+1;j<n;j++)
	        {
	            if(v[i]<v[j])
	            break;
	            else if(v[i]==v[j])
	            c++;
	        }
	        for(int j=i-1;j>=0;j--)
	        {
	            if(v[i]<v[j])
	            break;
	            else if(v[i]==v[j])
	            c++;
	        }
	        cout<<c<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}