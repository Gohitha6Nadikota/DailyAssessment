/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
*/

class Solution {
public:
    void check(int i,int j,string s,int & count)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
            count++;
        }
    }
    int countSubstrings(string s) 
    {
        int count=0;
        int n=s.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            check(i,i,s,count);
            check(i,i+1,s,count);
        }
        return count;
    }
};