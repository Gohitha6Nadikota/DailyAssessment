/*
    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
     Since the answer may be large, return the answer modulo 109 + 7.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    long ans = 0;

    vector<int> prevMin(n, -1);
    vector<int> nextMin(n, n);
    stack<int> stack;
    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && arr[stack.top()] > arr[i]) {
        const int index = stack.top();
        stack.pop();
        nextMin[index] = i;
      }
      if (!stack.empty())
        prevMin[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      ans += static_cast<long>(arr[i]) * (i - prevMin[i]) * (nextMin[i] - i);
      ans %= 1000000007;
    }

    return ans;
    }
};