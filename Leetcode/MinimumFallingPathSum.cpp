/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element
 in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
(row + 1, col), or (row + 1, col + 1).


*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int r=matrix.size();
        int c=matrix[0].size();
        int d[101][101];
        for(int i=0;i<c;i++)
        {
            d[0][i]=matrix[0][i];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int mini=100000;
                if(i-1>=0)
                mini=min(mini,d[i-1][j]);
                if(i-1>=0 && j-1>=0)
                mini=min(mini,d[i-1][j-1]);
                if(i-1>=0 && j+1<c)
                mini=min(mini,d[i-1][j+1]);

                 d[i][j]=mini+matrix[i][j];
            }
           
        }
        int sum=d[r-1][0];
        for(int i=1;i<r;i++)
        {
            sum=min(sum,d[r-1][i]);
        }
        return sum;

    }
};
