/*
You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. 
Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.
*/


class Solution {
  public:
    bool hasCycle(vector<vector<int>>&g,vector<bool>&vis,int p,int n,int index)
    {
        vis[index]=true;
        for(auto x: g[index])
        {
            if(x!=p)
            {
                if(vis[x]==false)
                {
                    if(hasCycle(g,vis,index,n,x))
                    return true;
                }
                else if(x!=p)
                return true;
            }
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<vector<int>>g(n);
        for(auto x:adj)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,false);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                if(c>1)
                return 0;
                if(hasCycle(g,vis,-1,n,i))
                return 0;
            }
        }
        return 1;
    }
};