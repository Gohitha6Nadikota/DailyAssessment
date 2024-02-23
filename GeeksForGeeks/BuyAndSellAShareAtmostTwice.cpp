/*
In daily share trading, a buyer buys shares in the morning and sells them on the same day. 
If the trader is allowed to make at most 2 transactions in a day, 
the second transaction can only start after the first one is complete (buy->sell->buy->sell).
 The stock prices throughout the day are represented in the form of an array of prices. 

Given an array price of size n, find out the maximum profit that a share trader could have made.
*/
class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
        int n = price.size();
        if (n <= 1) {
            return 0;
        }

        vector<int> profit(n, 0);

        int maxPrice = price[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, price[i]);
            profit[i] = max(profit[i + 1], maxPrice - price[i]);
        }

        int minPrice = price[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, price[i]);
            profit[i] = max(profit[i - 1], profit[i] + (price[i] - minPrice));
        }

        return profit[n - 1];
        }
};