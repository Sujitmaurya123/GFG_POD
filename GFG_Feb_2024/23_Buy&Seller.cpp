/*
Buy and Sell a Share at most twice

Question Link ==>>

https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // User function Template for C++

    int maxProfit(vector<int> &prices)
    {
        // Write your code here..

        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    if (buy == 1)
                    {
                        int buyit = -prices[index] + dp[index + 1][0][limit];
                        int skip = 0 + dp[index + 1][1][limit];
                        dp[index][buy][limit] = max(buyit, skip);
                    }
                    else
                    {
                        int sell = prices[index] + dp[index + 1][1][limit - 1];
                        int skip = 0 + dp[index + 1][0][limit];
                        dp[index][buy][limit] = max(sell, skip);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};