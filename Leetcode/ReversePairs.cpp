/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length
nums[i] > 2 * nums[j]


Approach is to use merge sort divide and combine concept to count the number of possible pairs which reduces the TC from O(n^2)
to O(nlogn)

*/

class Solution {
public:
    int countPairs(vector<int>&nums,int low,int high,int mid)
    {
        long long int count=0;
        long long int second=mid+1;
        for(long long int i=low;i<mid+1;i++)
        {
            while(second<high+1 && nums[i]>2*(long long)nums[second]) // moving until the condition fails
            {
                second++;
            }
            count+=second-mid-1; //if the element follows the condition then all the below elements follow the conditon 
        }
        return count;
    }
    void merge(vector<int>&nums,int low,int high,int mid)
    {
        vector<int>temp;
       long long int p1=low,p2=mid+1;
        while(p1<mid+1 && p2<high+1)
        {
            if(nums[p1]<nums[p2])
            {
                temp.push_back(nums[p1]);
                p1++;
            }
            else
            {
                temp.push_back(nums[p2]);
                p2++;
            }
        }
        while(p1<mid+1)
        {
           temp.push_back(nums[p1]);
                p1++; 
        }
        while(p2<high+1)
        {
            temp.push_back(nums[p2]);
                p2++;
        }
        for(long long int i=low;i<high+1;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    int mergeSort(vector<int>&nums,int left,int right)
    {
        long long int c=0;
        if(left<right)
        {
            long long int mid=(left+right)/2;
            c+=mergeSort(nums,left,mid);
            c+=mergeSort(nums,mid+1,right);
            c+=countPairs(nums,left,right,mid);
            merge(nums,left,right,mid);
        }
        return c;
    }
    int reversePairs(vector<int>& nums) 
    {
        return mergeSort(nums,0,nums.size()-1);
    }
};

