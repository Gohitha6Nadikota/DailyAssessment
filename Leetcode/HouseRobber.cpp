/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
 return the maximum amount of money you can rob tonight without alerting the police.
*/

int func(vector<int>nums,vector<int>&dp,int index,int n)
    {
        if(index==n || index==n+1)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int a=nums[index]+func(nums,dp,index+2,n);
        int b=func(nums,dp,index+1,n);
        dp[index]=max(a,b);
        return dp[index];
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(nums,dp,0,n);
    }