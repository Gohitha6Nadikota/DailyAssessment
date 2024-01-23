/*
You are given an array of strings arr. 
A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements 
without changing the order of the remaining elements.
*/


class Solution {
public:
    bool canAdd(string &a,string &b)
    {
        set<char>s;
        for(auto x:a)
            s.insert(x);
        for(auto x:b)
            s.insert(x);
        return s.size()==(a.size()+b.size());
    }
    void func(vector<string>&arr,string p,int index,int &ans)
    {
        if(p.size()>ans)
            ans=p.size();
        for(int i=index;i<arr.size();i++)
        {
            if(canAdd(p,arr[i]))
                func(arr,p+arr[i],i+1,ans);
        }
    }
    int maxLength(vector<string>& arr) 
    {
        int ans=0;
        func(arr,"",0,ans);
        return ans;
    }
};