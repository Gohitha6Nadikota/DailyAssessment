/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
*/

class Solution {
public:
    void func(int i,vector<int>&ans,int l,int h,int val)
    {
        if(val>=l && val<=h)
            ans.push_back(val);
        if(val>h || i>9)
            return;
        else
            func(i+1,ans,l,h,val*10+i);
    }
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>ans;
        for(int i=1;i<10;i++)
        {
            func(i,ans,low,high,0);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};