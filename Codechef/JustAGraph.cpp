/*
You are given an undirected graph with N nodes (numbered 1 through N). For each valid i-th node has a weight Wi.
 Also, for each pair of nodes i and j, there is an edge connecting these nodes if 
j-i != wj-wi
Find the number of connected components in this graph.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        
        int flag = 0;
        
        for (int i = 1; i < N; i++) 
        {
            if ((A[i] - A[i - 1]) != 1)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag) 
        {
            cout << 1 << endl;
        }
        else {
            cout << N << endl;
        }
    }
    
    return 0;
}
