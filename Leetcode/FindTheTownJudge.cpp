/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi]
representing that the person labeled ai trusts the person labeled bi. 
If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        map<int,int>m;
        map<int,int>t;
        for(int i=0;i<trust.size();i++)
        {
            m[trust[i][0]]++;
            t[trust[i][1]]++;
        }
        int judge;
        for(int i=0;i<n;i++)
        {
            if(m.find(i+1)==m.end())
              judge=i+1;  
        }
        if(t[judge]==n-1)
            return judge;
        return -1;
    }
};