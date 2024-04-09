/*
Minimum Points To Reach Destination

Question Link->
https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int minPoints(int m, int n, vector<vector<int>> points)
    {
        // Your code goes here
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = max(1, 1 - points[m - 1][n - 1]);
        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - points[i][n - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            dp[m - 1][i] = max(1, dp[m - 1][i + 1] - points[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]);
            }
        }
        return dp[0][0];
    }
};