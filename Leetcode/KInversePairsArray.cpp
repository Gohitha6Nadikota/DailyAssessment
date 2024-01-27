/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that 
there are exactly k inverse pairs. 
Since the answer can be huge, return it modulo 109 + 7.
*/

class Solution {
public:
     const int mod=int(1e9+7);
    int kInversePairs(int n, int k) {
        vector<int> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=1;
        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                curr[K] = (prev[K] + (K > 0 ? curr[K - 1] : 0)) % mod;
                curr[K] = (curr[K] + mod - (K >= N ? prev[K-N] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
};