/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/


class Solution {
public:
    int numSquares(int n)
    {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int start=1;
        while(start*start<=n)
        {
            for(int i=start*start;i<=n;i++)
                dp[i]=min(dp[i-start*start]+1,dp[i]);
            start++;
        }
        return dp[n]; 
    }
};