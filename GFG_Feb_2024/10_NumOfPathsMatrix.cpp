/*
Number of paths in a matrix with k coins

Question Link -->>

https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

*/



#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    long long int rec(int i, int j, int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
    {
        if (i >= n || j >= n || k < 0)
            return 0;
        if (i == n - 1 && j == n - 1)
            return k == arr[i][j];

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        return dp[i][j][k] = rec(i + 1, j, k - arr[i][j], arr, dp) + rec(i, j + 1, k - arr[i][j], arr, dp);
    }

public:
    long long numberOfPath(int N, int k, vector<vector<int>> &arr)
    {

        // Code Here
        n = N;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return rec(0, 0, k, arr, dp);
    }
};