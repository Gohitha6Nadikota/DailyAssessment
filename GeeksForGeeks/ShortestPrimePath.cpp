/*
You are given two four digit prime numbers num1 and num2. 
Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time
such that every number that we get after changing a digit is a four digit prime number with no leading zeros.
*/

//User function Template for C++
class Solution{   
public:
    int solve(int n1,int n2)
    {   
      int n=1000;
      bool isprime[n+1];
        fill(isprime,isprime+n+1,true);
        isprime[1]=false;
        unordered_map<int,int>mp;
        for(int i=2;i<=1000;i++)
        {
            if(isprime[i])
            {
                for(int j=i*i;j<=9999;j+=i)
                {
                    if(j<=1000)
                    isprime[j]=false;
                    if(j>=1000)
                    {
                        mp[j]=-1;
                    }
                }
            }
        }
        unordered_set<int>st;
        for(int i=1000;i<=9999;i++)
        {
            if(mp[i]!=-1)st.insert(i);
        }
        queue<int>q;
        unordered_map<int,int>ans;
        ans[n1]=0;
        q.push(n1);
        int res=-1;
        while(!q.empty())
        {
            int it=q.front();
            q.pop();
            if(it==n2)
            {
                res=ans[it];
                break;
            }
            int numatpos;
            int z=1;
            for(int i=1;i<=4;i++)
            {
                z*=10;
                int x=z/10;
                numatpos=it/x;
                numatpos=(numatpos%10)*x;
                int num=it-numatpos;
                for(int j=0;j<=9;j++)
                {
                   int newnum=num+j*x;
                   if(newnum==it)continue;
                 
                   if(st.find(newnum)!=st.end())
                   {
                    if(ans[newnum]==0 )
                    {
                        q.push(newnum);
                        ans[newnum]=ans[it]+1;
                    }
                    else
                    {
                        if(ans[newnum]>ans[it]+1)
                        {
                            ans[newnum]=ans[it]+1;
                            q.push(newnum);
                        }
                    }
                    
                   }
                    
                }
            }
        }
        return res;
    }
};