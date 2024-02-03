/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. 
Test cases are generated so that the answer fits in a 32-bit integer.


*/

class Solution {
public:
    int func(int index,vector<int>&dp,int k,vector<int>&v)
    {
       if(index>=v.size()) 
           return 0;
        if(dp[index]!=-1)
            return dp[index];
        int m=0,ans=0;
        int e=v.size();
        e=min(index+k,e);
        for(int i=index;i<e;i++){
        m=max(m,v[i]);
        ans=max(ans,m*(i-index+1)+func(i+1,dp,k,v));
        }
        return dp[index]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        vector<int>dp(arr.size(),-1);
        return func(0,dp,k,arr);
    }
};