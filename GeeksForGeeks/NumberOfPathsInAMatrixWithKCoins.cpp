/*
Given a n x n matrix such that each of its cells contains some coins.
Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. 
From a cell (i, j), you can only move to (i+1, j) or (i, j+1).
*/

class Solution {
public:
    long long func(vector<vector<vector<int>>>&dp,vector<vector<int>>&arr,int i,int j,int sum,int n)
    {
        if(i==n-1 && j==n-1)
        return sum==arr[i][j];
        if(i<0 || j<0 || i>=n || j>=n || sum<=0)
        return 0;
        if(dp[i][j][sum]!=-1)
        return dp[i][j][sum];
        return dp[i][j][sum]=func(dp,arr,i,j+1,sum-arr[i][j],n)+func(dp,arr,i+1,j,sum-arr[i][j],n);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {    
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return func(dp,arr,0,0,k,n);
    }
};