/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a,b;
        int n=nums.size();
            
        for(auto x:nums)
        {
            if(x<0)
                b.push_back(x);
            else
                a.push_back(x);
        }
        nums.clear();
        for(int i=0;i<n/2;i++)
        {
            nums.push_back(a[i]);
            nums.push_back(b[i]);    
        }
        return nums;
    }
};