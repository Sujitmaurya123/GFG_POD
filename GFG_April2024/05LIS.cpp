/*
Strictly Increasing Array

Question Link->
https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LIS(vector<int> &arr)
    {

        int n = arr.size(), temp = 1;

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] - arr[j] >= i - j)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                temp = max(temp, dp[i]);
            }
        }
        return temp;
    }
    int min_operations(vector<int> &nums)
    {
        // Code here
        int n = LIS(nums);
        int k = nums.size();
        return k - n;
    }
};