/*
Lucy had recently learned the game, called Natural Numbers.

The rules of the game are really simple. There are N players.
 At the same time, every player says one natural number. Let's call the number said by the i-th player Ai.
  The person with the smallest unique number (that is, the smallest number that was not said by anybody else) wins.
 Sometimes, there is a case when there are no unique numbers at all. Then the game is obviously a draw, so nobody wins it.

Sometimes, it's hard to determine the winner, especially, when the number of players is enormous. 
So in this problem, your assignment will be: given the names of the players and the numbers every of them have said. 
Please, tell the name of the winner, or determine that nobody wins.

*/


#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;

int main() {
	// your code goes here
	high t; 
	cin>>t;
	while(t--)
	{
	    int n,ans=0;cin>>n;
	    map<int,string>mn;
	    map<int,int>mc;
	    for(int i=0;i<n;i++){
	        string S;int x;
	        cin>>S>>x;
	        mn[x]=S;
	        mc[x]++;
	    }
	    for(auto i:mc){
	        if(i.second==1){ans=i.first;break;}
	    }
	    if(ans==0)cout<<"Nobody wins.\n";
	    else cout<<mn[ans]<<endl;
	}
	return 0;
}
