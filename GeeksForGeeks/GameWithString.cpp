/*
Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal 
of k characters. The value of a string is defined as the sum of squares of the count of each distinct character 
present in the string. 

*/


class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<int,int>m;
        for(auto x:s)
        {
            m[x-'a'+1]+=1;
        }
        priority_queue<int>pq;
        for(auto x:m)
        pq.push(x.second);
        
        while(k--)
        {
            int c=pq.top();
            pq.pop();
            pq.push(c-1);
        }
        int ans=0;
        while(pq.size())
        {
            int p=pq.top();
            ans+=p*p;
            pq.pop();
        }
        return ans;
    }
};