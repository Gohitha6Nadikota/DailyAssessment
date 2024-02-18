/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the
 half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free.
 The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, 
return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.
*/


class Solution {
public:
   
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end());
        unordered_map<int,int>count;
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>busy;
        priority_queue<int,vector<int>,greater<int>>free;
        for(int i=0;i<n;i++)
            free.push(i);
        for(auto x: meetings)
        {
            int start=x[0],end=x[1];
            while(busy.size()>0 && busy.top().first<=start)
            {
                int done=busy.top().second;
                busy.pop();
                free.push(done);
            }
            if(free.size()>0)
            {
                int select=free.top();
                free.pop();
                count[abs(select)]+=1;
                busy.push({end,select});
            }
            else
            {
                pair<long long , int> topmost=busy.top();
                busy.pop();
                count[abs(topmost.second)]+=1;
                long long newt=topmost.first;
                newt+=(end-start);
                busy.push({newt,topmost.second});
            }
        }
        int mx=0;
        for(int i=1;i<n;i++)
        {
            if(count[i]>count[mx])
            {
                mx=i;
            } 
        }
        return mx;
    }
};