/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/

class Solution {
public:
    static bool cmp(pair<char,int>&a,pair<char,int>&b)
        {
        if(a.second>b.second)
            return true;
       return false;
    }
    string frequencySort(string s) 
    {
        map<char,int>m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        vector<pair<char,int>>v;
        for(auto x : m)
       v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),cmp);
        string z="";
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].second;j++)
            {
                z+=v[i].first;
            }
        }
        return z;
    }
};