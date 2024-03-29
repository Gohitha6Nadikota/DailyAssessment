/*

There is a ritual that some monks of Byteland perform every century as a sign of respect and worship towards BOOL, the God of Byteland.

All the monks train for many years in order to accomplish an extremely hard task, that is the one of accessing the sacred temple of Byteland, where only the best of the bests monks are allowed to enter and worship their god, BOOL.

The training the monks perform, usually consists of several physically and intellectually challenging tasks, trained and perfected over the course of many years, so that one of them can be eligible for the ultimate task that is a combination of both physical effort as well as mental effort.

This final task is the actual possibility of trying to access the sacred temple of Byteland, that is located on the top of a very high mountain, where reckless storms and heavy rains usually occur.

The access to this mountain is done by climbing an enourmous set of stairs that spiral around the mountain until it ends on the top of the mountain where the sacred temple door is located.

The door can only be opened by unlocking it. To unlock the door, the monk only sees a hole in it, a lever, and he also spots a very large amount of little round stones on the ground, and he understands that the only way to open the door is to place an exact pre-determined amount of stones trough that hole, so that when the number is correct, he will push the lever down, and the door will open. If this number is incorrect, the lever will be locked by the incorrect stones and a whole new century must pass so that the storms can erode the stones and a new monk can be selected for the task.

This year, YOU were the one selected to climb the huge set of stairs, and you are extremely well prepared... You have done your training very well and you are also aware of two very important facts that will be key for your success... The favourite number base on Byteland is base 2, and Gods favourite number is the largest number on this base. You also know that the number of stones you need to place on the door hole is related to the way everyone climbs the stairs and with the number of stairs itself.

As the monks take several supplies for the demanding trip, they can only climb either one or two steps at a time. You understood that the number of stones you need to place on the door is closely related with the way you climb the stairs. Suppose the number of stairs you need to climb is N. Also, let the number of ways you have of climbing those N stairs be M. Now, the number of stones required is equal to the number of 1's in the base-2 representation of (M modulo 1000000007).

You won't fail, as you are extremely well ready, but you have made everyone on your town extremely excited with your journey, so, given the number N of steps you are to climb and a guess, G, from the people of your village, you need to see if they are correct or not.

More formally, given a number N of steps to climb and a guess G from your village, you need to check if guess G is accordingly to your correct calculations. They are correct if you manage to enter the temple using their guess, or incorrect otherwise. You should output the string “CORRECT” if they are correct, or “INCORRECT” if they are incorrect. (Quotes for clarity only). Please read the section "Output Explanation" for some clarification on the example cases.

*/

#include <bits/stdc++.h>
#define high long long
#define mod 1000000007
#define MAXN 1000000
using namespace std;
long long func(long long x){
    long long count = 0;
    while(x){
        count = count + (x & 1);
        x>>=1;
    }
    return count;
}
int main() {
	// your code goes here
	long long table[MAXN + 1];
	table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    for(int i=3; i<=MAXN; i++){
        table[i] = (table[i-1]%mod + table[i-2]%mod)%mod;
    }
	high t; 
	cin>>t;
	while(t--)
	{
	    int n,r; cin>>n>>r;
	    if(func(table[n])==r)
	    cout<<"CORRECT";
	    else
	    cout<<"INCORRECT";
	    cout<<endl;
	}
	return 0;
}
