/*
There are n cities connected by some number of flights. You are given an array flights where 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
 If there is no such route, return -1.

 
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int>cost(n,INT_MAX);
        vector<vector<pair<int,int>>>details(n);
        for(auto x:flights)
            details[x[0]].push_back({x[1],x[2]});
        queue<pair<int,int>>q;
        q.push({src,0});
        int count=0;
        while(!q.empty()&& count<=k)
        {
            int m=q.size();
            while(m--)
            {
                auto [a,p]=q.front();
                q.pop();
                for(auto [x,c]: details[a])
                {
                    if((c+p)<cost[x])
                    {
                        cost[x]=c+p;
                        q.push({x,cost[x]});
                    }
                }
            }
            count++;
        }
        if(cost[dst]==INT_MAX)
            return -1;
        else
            return cost[dst];
    }
};