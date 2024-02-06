/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        map<string,int>mp;
        int k=1;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            if(mp[s]==0)
            {
                mp[s]=k;
                ans.push_back({strs[i]});
                k++;
            }
            else
            {
                ans[mp[s]-1].push_back(strs[i]);
            }
        }
        return ans;
    }
};