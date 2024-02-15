/*
You are presented with an undirected connected graph consisting of n vertices and connections between them
 represented by an adjacency matrix. Your objective is to determine whether it is possible to start traversing from a node,
  x, and return to it after traversing all the vertices at least once, using each edge exactly once.

*/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n=paths.size();
	    int m=paths[0].size();
	    for(int i=0;i<n;i++)
	    {
	        int c=0;
	        for(int j=0;j<m;j++)
	        {
	            if(paths[i][j])
	            c++;
	        }
	        if(c%2)
	        return 0;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends