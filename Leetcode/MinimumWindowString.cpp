/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/


class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n1=s.size();
        int n2=t.size();
        map<char,int>m;
        for(auto x: t)
            m[x]++;
        int start=0,end=0,ans=INT_MAX,point=0;
        while(end<n1)
        {
            if(m[s[end]]>0)
                n2--;
            m[s[end]]--;
            end++;
            while(n2==0)
            {
                if(end-start<ans)
                {
                    point=start;
                    ans=end-start;
                }
                if(m[s[start]]==0)
                {
                    n2++;
                }
                m[s[start]]++;
                start++;
            }
        }
        if(ans==INT_MAX)
            return "";
        else
            return s.substr(point,ans);
    }
};