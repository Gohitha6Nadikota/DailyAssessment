/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum 
dd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created
 from the given combination.

Note that the resulting string can have leading zeros.
*/


class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int c1=0,c0=0;
        for(auto x: s)
        {
            if(x=='1')
                c1++;
            else 
                c0++;
        }
        string ans="";
        if(c1<2)
        {
            for(int i=0;i<c0;i++)
                ans+='0';
            for(int i=0;i<c1;i++)
                ans+='1';
        }
        else
        {
            for(int i=0;i<c1-1;i++)
                ans+='1';
            for(int i=0;i<c0;i++)
                ans+='0';
            ans+='1';
        }
        return ans;
        
    }
};