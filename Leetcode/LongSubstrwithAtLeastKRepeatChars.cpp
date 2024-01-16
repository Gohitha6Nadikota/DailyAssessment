/*
Given a string s and an integer k,
return the length of the longest substring of s 
such that the frequency of each character in this substring is greater than or equal to k.
*/

class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n=s.size();
        if(n<k)    // if string length is less than the repetiton count ,it is not possible 
            return 0;
        else if(k<=1)  // if the repetition count is 0 or 1 then the whole string can be considered
            return n;
        map<char,int>m; // Maintains the count of each character
        for(auto x:s)
            m[x]++;
        int start=0;
        while(start<n && m[s[start]]>=k)  // checks for all the acceptable characters
            start++;
        if(start>=n-1) //if the whole string is acceptable return the value
            return start;
        int c1=longestSubstring(s.substr(0,start),k);  // Breaking into two halves 
        while(start<n && m[s[start]]<k) // avoiding the unnecessary characters 
            start++;
        int c2=0;
        if(start<n)
            c2=longestSubstring(s.substr(start),k); // Checcking the last half
        return max(c1,c2); // picking the best
    }
};