/*
A tennis tournament is about to take place with N players participating in it.
 Every player plays with every other player exactly once and there are no ties. 
 That is, every match has a winner and a loser.
With Naman's birthday approaching, he wants to make sure that each player wins the same number of matches 
so that nobody gets disheartened.
Your task is to determine if such a scenario can take place and if yes find one such scenario.
*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
using namespace std;
vector<int> func(vector<int> &vec)
{
    int x = vec[vec.size() - 1];
    vec.pop_back();
    reverse(vec.begin(), vec.end());
    vec.push_back(x);
    reverse(vec.begin(), vec.end());
    return vec;
}

int main() {
	// your code goes here
	
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    vector<int>v;
	    if(n%2==0)       // if there are even people then it is not possible
	    cout<<"NO"<<endl;
	    else{
	        cout<<"YES"<<endl;
	        int z=n/2 +1,y=n/2;
	        while(z--)
	        v.push_back(0);
	        
	        while(y--)
	        v.push_back(1);
	        
	        while(n--){
	            for(int i=0;i<v.size();i++)
	            cout<<v[i];
	            
	            cout<<endl;
	           // func(v);
	             int x = v[v.size() - 1];
    v.pop_back();
    reverse(v.begin(), v.end());
    v.push_back(x);
    reverse(v.begin(), v.end());

	        }
	        
	        
	    }
	}
	
	return 0;
}