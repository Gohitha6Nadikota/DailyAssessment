/*
You are given an array of positive integers nums of length n.

A polygon is a closed plane figure that has at least 3 sides.
 The longest side of a polygon is smaller than the sum of its other sides.

Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and
 a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

The perimeter of a polygon is the sum of lengths of its sides.

Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 
if it is not possible to create a polygon.
*/


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long int>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==3)
        {
            if((nums[0]+nums[1])>nums[2])
                return nums[0]+nums[1]+nums[2];
            else
                return -1;
        }
        else
        {
            int n=nums.size();
            long long int sum=0;
            for(int i=0;i<n;i++)
            {
                v.push_back(sum);
                sum+=nums[i];
                //cout<<sum<<endl;
            }
            long long int y=-1;
            v.push_back(sum);
            for(int i=0;i<n;i++)
            {
                //cout<<v[i]<<" "<<nums[i]<<endl;
                if(v[i]>nums[i])
                    y=v[i+1];
            }
            return y;
        }
    }
};