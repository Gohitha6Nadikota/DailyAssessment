/*
Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
         for(auto x: words)
          {
             string x1=x;
             reverse(x1.begin(),x1.end());
             if(x1==x)
                 return x;
         }
        return "";
    }
};