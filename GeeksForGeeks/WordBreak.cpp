/*
Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of
 dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.
*/

class Solution
{
public:
    int func(vector<int>&dp,string &A,set<string>&s,int n,int index)
    {
        if(index==n)
        return true;
        if(dp[index]!=-1)
        return dp[index];
        for(int i=index;i<n;i++)
        {
            if(s.count(A.substr(index,i-index+1)) && func(dp,A,s,n,i+1))
            {
                dp[index]=1;
                return true;
            }
        }
        dp[index]=0;
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.size();
        vector<int>dp(n,-1);
        set<string>s;
        for(auto x:B)
        s.insert(x);
        return func(dp,A,s,n,0);
    }
};