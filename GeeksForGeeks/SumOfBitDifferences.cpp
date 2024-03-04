/*
Given an array integers arr[], containing n elements, find the sum of bit differences between all 
pairs of element in the array. 
Bit difference of a pair (x, y) is the count of different bits at the same positions in
 binary representations of x and y.
For example, bit difference for 2 and 7 is 2. 
Binary representation of 2 is 010 and 7 is 111 respectively and the first and last bits differ
 between the two numbers.
*/

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long cnt = 0;
        for(int i=31;i>=0;i--){
           long a = 0;
           for(int j=0;j<n;j++){
               a+=(arr[j]>>i)&1;
           }
           cnt += 2*a*(n-a);
        }
        return cnt;
	}
};