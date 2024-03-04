/*
Given an 0-indexed array of integers arr[] of size n, find its peak element. 
An element is considered to be peak
 if it's value is greater than or equal to the values of its adjacent elements (if they exist).
*/

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int low = 0 ,high = n-1;
       while(low <= high){
           int mid = (low+high)/2;
           if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
               return mid;
           }
           if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
               low++;
           }
           else high--;
       }
       return low;
    }
};