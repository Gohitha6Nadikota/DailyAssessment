/*
Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.
In other words, you have to iterate over the array, and after each index,
determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. 
An array will be formed for each iteration and stored in an array of arrays. 
If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. 
If two numbers have equal frequency, place the smaller number first in the array.
*/


vector<vector<int>> ans;
        vector<int> v,mp(101,0);
        int z;
        for(int i=0;i<n;i++){
            if(a[i]==0) continue;
            z=a[i];mp[z]++;
            for(int j=0;j<v.size();j++){
                if(a[i]==v[j]){
                    v[j]=z;
                    z=-1;
                    break;
                }
                if(mp[v[j]]>mp[z]) continue;
                if(mp[v[j]]<mp[z]) swap(v[j],z);
                else{
                    if(z<v[j]) swap(v[j],z);
                }
            }
            if(z!=-1&&v.size()<k) v.push_back (z);
            ans.push_back (v);
        }
        return ans;
    }