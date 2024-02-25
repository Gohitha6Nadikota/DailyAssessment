/*
Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of distinct combinations to reach the given score.
*/

public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long >dp(n+1,0);
    	dp[0]=1;
    	for(int  i=3;i<=n;i++)
    	dp[i]+=dp[i-3];
    	for(int i=5;i<=n;i++)
    	dp[i]+=dp[i-5];
    	for(int i=10;i<=n;i++)
    	dp[i]+=dp[i-10];
    	
    	return dp[n];
    	
    }