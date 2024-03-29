/*
Given an array nums containing 
n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum;
        sum=(n*(n+1))/2;
        int ans=sum-accumulate(nums.begin(),nums.end(),0);
        return ans;
    }
};