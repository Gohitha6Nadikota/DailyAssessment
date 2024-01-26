/*
There is an m x n grid with a ball.
 The ball is initially at the position [startRow, startColumn].
  You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid
   crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, 
return the number of paths to move the ball out of the grid boundary. Since the answer can be very large,
 return it modulo 109 + 7.
*/

class Solution {
public:
    int func(vector<vector<vector<int>>>&dp,int m,int n,int max,int r,int c)
    {
        if(r<0 || c<0 || r>=m || c>=n)
            return 1;
        if(max==0)
            return 0;
        if(dp[r][c][max]!=-1)
            return dp[r][c][max];
              int a1=func(dp,m,n,max-1,r-1,c);
                int b1=func(dp,m,n,max-1,r+1,c);
                int c1=func(dp,m,n,max-1,r,c-1);
                int d1=func(dp,m,n,max-1,r,c+1);
            return dp[r][c][max]=((a1+b1)%1000000007+(c1+d1)%1000000007)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return func(dp,m,n,maxMove,startRow,startColumn);
    }
};