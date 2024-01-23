/*
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks,
 for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. 
Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them.
If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", 
on returning an empty array. 
Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 
*/

//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        vector<int>adj[n];
        for(int i=0; i<m; i++){
            if(p[i][1]==p[i][0])
            return {};
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>ans, id(n, 0);
        for(int i=0; i<n; i++){
            for(auto &it:adj[i]){
                id[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(id[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it:adj[node]){
                id[it]--;
                if(id[it]==0) q.push(it);
            }
        }
        if(ans.size()<n) return {};
        return ans;
    }
};

// Topological sort is used where there is a chance of cycles in the graph.
// It works on the indegree of the node