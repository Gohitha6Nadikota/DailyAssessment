/*
Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings.
For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.
A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than or equal 
to the sum of the digits of the sub-group immediately right to it. 
Your task is to determine the total number of valid groupings that could be done for a given string.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int func(int i, int prevSum, string &s,vector<vector<int>> &dp) 
	{
        int n = s.length();
        if (i == n) return 1;
        if(dp[i][prevSum]!=-1) return dp[i][prevSum];
        int ans = 0,currSum = 0;
        for (int k = i; k < n; k++) 
        {
            currSum += s[k] - '0';
            if (currSum >= prevSum) 
            {
                ans += func(k + 1, currSum, s, dp);
            }
        }
        
        return dp[i][prevSum] = ans;
    }
	int TotalCount(string str){
	    // Code here
	    int n = str.length();
        vector<vector<int>>dp(n, vector<int>(1000, -1));
        return func(0, 0, str, dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends