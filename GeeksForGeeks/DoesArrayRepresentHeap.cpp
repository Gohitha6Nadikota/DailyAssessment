/*
Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.
*/



class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=0;i<n;i++)
        {
            if(2*i+1<n)
            {
                if(arr[i]<arr[2*i+1])
                return false;
            }
            if(2*i+2<n)
            {
                if(arr[i]<arr[2*i+2])
                return false;
            }
        }
        return true;
    }
    
};