/*
You are given an integer array nums of size n and a positive integer k.
Divide the array into one or more arrays of size 3 satisfying the following conditions:
Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. 
If it is impossible to satisfy the conditions, return an empty array. 
And if there are multiple answers, return any of them.
*/


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()
);
        int n=nums.size();
     vector<vector<int>>ans;
        vector<int>v;
     for(int i=1;i<=n;i++)
     {
         v.push_back(nums[i-1]);
         if(i%3==0)
         {
             ans.push_back(v);
             v.clear();
         }
     }
     for(int i=0;i<n/3;i++)
     {
        if(ans[i][2]-ans[i][0]>k)
            return {};
     }
        return ans;
    }
};