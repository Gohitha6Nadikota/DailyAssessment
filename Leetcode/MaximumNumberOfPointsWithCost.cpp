/*
You are given an m x n integer matrix points (0-indexed).
Starting with 0 points, you want to maximize the number of points you can get from the matrix.
To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. 
For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), 
picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
Return the maximum number of points you can achieve.
*/



class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int m=points.size();
        int n=points[0].size();
        vector<long long int>v(n+1,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)  //considering elements which are before 
            {
                v[j]+=points[i][j];  
                if(j>0)
                    v[j]=max(v[j],v[j-1]-1);
            }
            for(int j=n-2;j>=0;j--)  // considering elements while are after
            {
                v[j]=max(v[j],v[j+1]-1); 
            }
        }
        long long int mx=v[0];
        for(auto x:v)
            mx=max(mx,x);
        return mx;
    }
};