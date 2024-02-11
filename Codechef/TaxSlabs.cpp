/*
In India, every individual is charged with income tax on the total income each year. 
This tax is applied to specific ranges of income, which are called income tax slabs. 
The slabs of income tax keep changing from year to year. 
This fiscal year (2020-21), the tax slabs and their respective tax rates are as follows:

You are given Chef's total income: N rupees (Rs.). Find his net income. 
The net income is calculated by subtracting the total tax (also called tax reduction) from the total income.
Note that you do not need to worry about any other kind of tax reductions, only the one described above.
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
        high temp=n;
        high sum=0;
        for(int i=0; i<=25; i+=5)
        {
        if(n>250000)
            sum+=(i*(250000)/100);
        else
        {
            sum+=((i*n)/100);
            n=0;
            break;
        }
        n-=250000;
    }
    if(n>0)
        sum+=((30*n)/100);
    
    cout<<(temp-sum)<<endl;
	}
	return 0;
}
