/*
Optimal Strategy For A Game
Question Link->
https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

*/

// Function to find the maximum possible amount of money we can win.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int i, int j, int arr[], vector<vector<long long>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int x = arr[i] + min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp));
        int y = arr[j] + min(solve(i + 1, j - 1, arr, dp), solve(i, j - 2, arr, dp));

        return dp[i][j] = max(x, y);
    }
    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return solve(0, n - 1, arr, dp);
    }
};