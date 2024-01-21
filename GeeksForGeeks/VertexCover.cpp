/*
Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. 
You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.

*/

//User function Template for C++

class Solution{
    public:
        void func(int index,vector<pair<int,int>>&edges,set<int>&s,int &n,int &ans)
        {
            if(index>n)
            {
                for(auto x:edges)  
                {
                    if(s.find(x.first)==s.end() && s.find(x.second)==s.end())
                    return;
                }
               int n1=s.size();
            ans=min(n1,ans);
            return;
            }
            func(index+1,edges,s,n,ans);
            s.insert(index);
            func(index+1,edges,s,n,ans);
            s.erase(index);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                int ans=INT_MAX;
                set<int>s;
                func(1,edges,s,n,ans);
                return ans;
            }
};