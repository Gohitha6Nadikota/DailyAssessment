/*
A number n can be broken into three parts n/2, n/3, and n/4 (consider only the integer part). 
Each number obtained in this process can be divided further recursively. 
Find the maximum sum that can be obtained by summing up the divided parts together.
Note: It is possible that we don't divide the number at all.
*/

class Solution
{
    public:
        int func(int n,vector<int>&dp)
        {
            if(n==0)
            return 0;
            if(dp[n]!=-1)
            return dp[n];
            return dp[n]=max({n,max(n/2,func(n/2,dp))+max(n/3,func(n/3,dp))+max(n/4,func(n/4,dp))});
        }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,-1);
            return func(n,dp);
        }
};