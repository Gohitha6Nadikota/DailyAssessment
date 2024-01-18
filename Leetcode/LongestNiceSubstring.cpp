/*
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase.
For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear.
 However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. 
If there are multiple, return the substring of the earliest occurrence. 
If there are none, return an empty string.


*/


class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.size();
        if(n<2)
            return "";
        map<char,int>m;
        for(auto x:s)
            m[x]++;
        for(int i=0;i<n;i++)
        {
            if(m.find(toupper(s[i]))==m.end() || m.find(tolower(s[i]))==m.end()) // checking for the character with no pair and split the string there
               {
                   string a=longestNiceSubstring(s.substr(0,i));
                   string b=longestNiceSubstring(s.substr(i+1));
                   if(a.size()>=b.size())
                       return a;
                   else
                       return b;
                  
               }
        }
       return s;
    }
};






  



            
        
     
   
