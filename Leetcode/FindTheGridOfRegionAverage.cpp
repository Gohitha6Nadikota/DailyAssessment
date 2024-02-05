/*
You are given a 0-indexed m x n grid image which represents a grayscale image, where image[i][j] 
represents a pixel with intensity in the range[0..255]. You are also given a non-negative integer threshold.

Two pixels image[a][b] and image[c][d] are said to be adjacent if |a - c| + |b - d| == 1.

A region is a 3 x 3 subgrid where the absolute difference in intensity between any two adjacent pixels is less than or 
equal to threshold.

All pixels in a region belong to that region, note that a pixel can belong to multiple regions.

You need to calculate a 0-indexed m x n grid result, where result[i][j] is the average intensity of the region to 
which image[i][j] belongs, rounded down to the nearest integer. If image[i][j] belongs to multiple regions,
 result[i][j] is the average of the rounded down average intensities of these regions, rounded down to the nearest integer. 
 If image[i][j] does not belong to any region, result[i][j] is equal to image[i][j].

Return the grid result.
*/


class Solution {
public:
    vector<pair<int,int>>v={{0,1},{1,0},{-1,0},{0,-1}};
    bool isAdjsObeyed(int p1,int p2,int e1,int e2,int n,int m,vector<vector<int>>& img, int thr)
    {
        for(int i=0;i<4;i++)
        {
            int p11=p1+v[i].first;
            int p22=p2+v[i].second;
            if(p11>=0 && p22>=0 && p11<n && p22<m && p11<=e1 && p22<=e2 && p11>=(e1-2) && p22>=(e2-2))
                if(abs(img[p11][p22]-img[p1][p2])>thr)
                    return false;
        }
        return true;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& img, int thr) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<vector<int>>>ans(n, vector<vector<int>>(m, vector<int>()));
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<m;j++)
            {
                int sum=0;
                bool isAgreed=true;
                for(int k=i-2;k<=i && isAgreed;k++)
                {
                    for(int l=j-2;l<=j && isAgreed;l++)
                    {
                        sum+=img[k][l];
                        if(isAdjsObeyed(k,l,i,j,n,m,img,thr)==false)
                        {
                            isAgreed=false;
                            break;
                        }
                    }
                }
                if(isAgreed)
                {
                    for(int k=i-2;k<=i && isAgreed;k++)
                    {
                        for(int l=j-2;l<=j && isAgreed;l++)
                        {
                            ans[k][l].push_back(sum/9);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j].size()>0)
                {
                    int avg1=0;
                    for(auto x: ans[i][j])
                        avg1+=x;
                    img[i][j]=avg1/ans[i][j].size();
                }
            }
        }
        return img;
    }
};