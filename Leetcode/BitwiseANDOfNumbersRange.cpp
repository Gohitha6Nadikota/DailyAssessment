/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=right)
        {
            count++;
            left=left>>1;
            right=right>>1;
        }
        return left<<count;
    }
};