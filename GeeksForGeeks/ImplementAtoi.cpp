/*
Given a string, s, 
the objective is to convert it into integer format without utilizing any built-in functions. 
If the conversion is not feasible, the function should return -1.

Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and 
rest are numeric.
*/
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int func(string s)
    {
        int ans=0;
        if(s[0]!='-')
        {
            for(auto x:s)
            ans=ans*10+(x-'0');
            return ans;
        }
        else
        {
            reverse(s.begin(),s.end());
            s.pop_back();
            reverse(s.begin(),s.end());
            for(auto x:s)
            ans=ans*10+(x-'0');
            return -1*ans;
        }
      
    }
    int atoi(string s) {
        //Your code here
        int c=0,n=s.size();
        for(auto x: s)
        {
            if(x>='0' && x<='9'){
            c++;
            }
        }
        if(c<n-1)
        {
            return -1;
        }
        else if(c==n-1 && s[0]!='-')
        {
            return -1;
        }
        else
        {
            return func(s);
        }
    }
};