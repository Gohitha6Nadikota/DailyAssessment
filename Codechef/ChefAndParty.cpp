/*
Tonight, Chef would like to hold a party for his N friends.
All friends are invited and they arrive at the party one by one in an arbitrary order. 
However, they have certain conditions — for each valid i, when the 
i-th friend arrives at the party and sees that at that point, strictly less than Ai
  other people (excluding Chef) have joined the party, this friend leaves the party; 
  otherwise, this friend joins the party.

Help Chef estimate how successful the party can be — 
find the maximum number of his friends who could join the party (for an optimal choice of the order of arrivals).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        int people[n];
        for (int i = 0; i < n; i++)
        {
            cin >> people[i];
        }
        sort(people, people + n);
        for (int i = 0; i < n; i++)
        {
            if (people[i] <= cnt)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
