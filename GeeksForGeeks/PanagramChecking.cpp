/*
Given a string s check if it is "Panagram" or not.
A "Panagram" is a sentence containing every letter in the English Alphabet.
*/

class Solution
{
    public:
    bool checkPangram (string s) 
    {
        map<char,int>m;
       
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z'){
            char c=toupper(s[i]);   
            m[c]++;
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                m[s[i]]++;
            }
            
        }
        return m.size()==26;
    }

};