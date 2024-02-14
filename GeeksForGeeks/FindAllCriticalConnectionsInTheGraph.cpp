/*
A critical connection refers to an edge that, upon removal, 
will make it impossible for certain nodes to reach each other through any path. 
You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1,
 and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. 
For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). 
Additionally, it is expected that you store the edges in sorted order.

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dfs(int i, int p, vector<int>& rank, int depth,vector<int> adj[], vector<vector<int> >& ans,
        vector<int>& vis)
    {
        rank[i]=depth;
        vis[i]=1;
        int minDepth=INT_MAX;
        for(auto x:adj[i])
        {
            if(x!=p)
            {
                if(vis[x])
                {
                    minDepth=min(minDepth,rank[x]);
                }
                else
                {
                    int miniRank=dfs(x,i,rank,depth+1,adj,ans,vis);
                    if(miniRank>rank[i])
                    {
                        ans.push_back({min(i,x),max(i,x)});
                    }
                    minDepth=min(miniRank,minDepth);
                }
            }
        }
        return minDepth;
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[])
	{
	    // Code here
	    vector<vector<int>>ans;
	    vector<int>rank(v,-1),vis(v,0);
	    dfs(0,-1,rank,0,adj,ans,vis);
	    sort(ans.begin(),ans.end());
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends