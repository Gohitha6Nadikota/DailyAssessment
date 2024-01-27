/*
Given an array p[] of length n used to denote the dimensions of a series of matrices
 such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. 
 Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but 
this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) 
denoting multiplication symbols.
 For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.
*/

// User function Template for C++
class Solution{
public:
    pair<int,string>dp[27][27];
    pair<int,string>func(int i,int j,int p[])
    {
        if(i==j)
        {
            string a="";
            a+='A'+i-1;
            return {0,a};
        }
        if(dp[i][j].second!="")
        return dp[i][j];
        int ans=INT_MAX;
        string a1="";
        for(int h=i;h<j;h++)
        {
            pair<int,string>a=func(i,h,p);
            pair<int,string>b=func(h+1,j,p);
            int s=p[i-1]*p[j]*p[h]+a.first+b.first;
            if(s<ans)
            {
                ans=s;
                a1="("+a.second+b.second+")";
            }
        }
        return dp[i][j]={ans,a1};
    }
    string matrixChainOrder(int p[], int n){
        // code here
        return func(1,n-1,p).second;
    }
};