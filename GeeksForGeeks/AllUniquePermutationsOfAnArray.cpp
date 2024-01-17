/*
Given an array arr[] of length n. 
Find all possible unique permutations of the array in sorted order.
 A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void func(vector<int> &arr ,int n,int index,set<vector<int>>&sans)
  {
      if(index==n)
      {
          sans.insert(arr);
          return;
      }
      for(int j=index;j<n;j++)
      {
          swap(arr[index],arr[j]);
          func(arr,n,index+1,sans);
          swap(arr[index],arr[j]);
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>>ans;
        set<vector<int>>sans;
        func(arr,n,0,sans);
        for(auto x: sans)
        ans.push_back(x);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}