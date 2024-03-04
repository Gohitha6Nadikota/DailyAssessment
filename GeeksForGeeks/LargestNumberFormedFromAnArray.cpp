/*
Given an array of strings arr[] of length n representing non-negative integers, 
arrange them in a manner, such that, after concatanating them in order, 
it results in the largest possible number. 
Since the result may be very large, return it as a string.
*/

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) 
	{
	    // code here
	      sort(arr.begin(),arr.end(),[](string a, string b){
            return a+b>b+a;
            });
        string ans="";
        for(auto it:arr){
            ans+=it;
        }
        return ans;
	}
};