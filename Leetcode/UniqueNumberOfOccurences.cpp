/*
Given an array of integers arr
return true if the number of occurrences of each value in the array is unique or false otherwise.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m,m1;
        for(auto x:arr)
            m[x]++;
        int n=m.size();
        for(auto x:m)
            m1[x.second]++;
        return m1.size()==n;
        
    }
};