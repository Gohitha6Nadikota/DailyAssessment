/*
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        int n=tp.size();
        stack<int>s;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==0 &&  tp[s.top()]<=tp[i])
                s.pop();
           if(s.size()>0)
           ans[i]=s.top()-i;
           s.push(i);
        }
        return ans;
    }
};