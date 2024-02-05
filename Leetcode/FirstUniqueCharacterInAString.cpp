/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>m;
        for(auto x:s)
            m[x]++;
        for(int i=0;i<s.size();i++)
            if(m[s[i]]==1)
                return i;
        return -1; 
    }
};