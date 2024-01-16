/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])==m.end())         //checking for the presene of the other number
                m[nums[i]]=i;           //Storing each element with its index
            else
                return {m[target-nums[i]],i};
        }
        return {-1,-1};
    }
};