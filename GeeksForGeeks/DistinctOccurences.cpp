/*
Given two strings s and t of length n and m respectively. 
Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.
*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int mod=1000000007;
      unordered_map<string,int>mp;
        mp[""]=1;
        for(int i=0;i<s.size();i++)
        {
            string k=t;
            for(int j=t.size()-1;j>=0;j--)
            {
                
                if(t[j]==s[i])
                {
                    
                     string l=k;
                     l.pop_back();
                  
                     mp[k]=(mp[k]+mp[l])%mod;
                }
               k.pop_back();
            }
        }
        return mp[t]%mod;
    }
};
 