/*
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
*/


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        map<int,int>m;
        for(auto x: arr)
            m[x]++;
        priority_queue<int>p;
        for(auto x: m)
           p.push(-1*x.second);
        while(k)
        {
            k+=p.top();
            //cout<<p.top();
            if(k>=0)
            {
                p.pop();
             }
            else
                break;
        }
        return p.size();
    }
};