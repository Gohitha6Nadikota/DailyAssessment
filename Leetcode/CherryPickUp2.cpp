/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] 
represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, 0)));
        dp[0][0][n - 1] = 0 == n - 1 ? grid[0][0] : grid[0][0] + grid[0][n - 1];
        for (int row = 1; row < m; row++) 
        {
            for (int c1 = 0; c1 < min(n, row + 1); c1++)
            {
                for (int c2 = max(0, n - 1 - row); c2 < n; c2++) 
                {
                    int prevMax = 0;
                    for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) 
                    {
                        for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++)
                        {
                                prevMax = max(prevMax, dp[row - 1][offset1][offset2]);
                        }
                    }
                    if (c1 == c2) 
                        dp[row][c1][c2] = prevMax + grid[row][c1];
                    else 
                        dp[row][c1][c2] = prevMax + grid[row][c1] + grid[row][c2];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                res = max(res, dp[m - 1][i][j]);    
            }
        }
        return res;
    }
};