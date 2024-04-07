/*
Maximize dot product

Question Link->
https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int j = 1; j <= m; j++)
            dp[0][j] = INT_MIN;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
        return dp[n][m];
    }
};