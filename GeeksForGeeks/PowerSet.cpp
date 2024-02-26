/*
Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

*/


class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> result;
	    int n = s.length();
	    for(int i = 1; i <= (1 << n); i++){
	        string c;
	        for(int j = 0; j < n; j++){
	            if((i & (1 << j)) > 0)
	                c.push_back(s[j]);
	        }
	        if(c.length() > 0)
   		        result.push_back(c);
	    }
           sort(result.begin(), result.end());
	    return result;
		}
};