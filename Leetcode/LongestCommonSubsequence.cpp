/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted 
without changing the relative order of the remaining characters.
*/

class Solution {
public:
    int check(vector<vector<int>>&dp,string &t1,string &t2,int l1,int l2,int index1,int index2)
    {
        if(index1==l1)
            return 0;
        if(index2==l2)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        int ans=0;
        if(t1[index1]==t2[index2])
            ans=1+check(dp,t1,t2,l1,l2,index1+1,index2+1);
        else
        {
            ans=max(check(dp,t1,t2,l1,l2,index1,index2+1),check(dp,t1,t2,l1,l2,index1+1,index2));
        }
        dp[index1][index2]=ans;
        return ans;
        
    }
    int longestCommonSubsequence(string t1, string t2) 
    {
        int l1=t1.size(),l2=t2.size();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return check(dp,t1,t2,l1,l2,0,0);
    }
};