/*
Given two integers m and n, try making a special sequence of numbers seq of length n such that
seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.
*/

class Solution{
public:
int solve(int index,int num,int m,int n)
{
    if(num>m || index>n)   //end of size or crossed maximum value
    {
        return 0;
    }
    if(index==n)  //exactly n elements 
    {
        if(num<=m)
        {
            return 1;
        }
        return 0;
    }
    
    int pick=0;
    for(int i=0;i<=m-num;i++)
    {
        if(2*num+i<=m)
        pick+=solve(index+1,2*num+i,m,n);
    }
    return pick;
    
}
    int numberSequence(int m, int n){
        // code here
        int count=0;
        for(int i=1;i<=m;i++)
        {
            count+=solve(1,i,m,n); //All possible sequences
        }
        return count;
    }
};

/*
int dp[101][101];
class Solution{
    int solve(int val,int ind,int m,int n,int &ans)
    {
        if(val>m) return 0;
        if(ind>=n-1) return val<=m;
        int res=0;
        // int res=0;
        if(dp[val][ind]!=-1) return dp[val][ind];
        for(int j=2*val;j<=m;++j)
        {
            res+=solve(j,ind+1,m,n,ans);
        }
        return dp[val][ind]=res;
    }
public:
    int numberSequence(int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<=m;++i)
        {
            //solve(val,ind,m,n)
            ans+=solve(i,0,m,n,ans);
        }
        return ans;
    }
};
*/