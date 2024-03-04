/*
Given an array arr of n positive integers. 
The task is to swap every ith element of the array with (i+2)th element.
*/

class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Your code here
        for(int i=0;i<n-2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[i+2];
            arr[i+2]=temp;
        }
        
    }
};