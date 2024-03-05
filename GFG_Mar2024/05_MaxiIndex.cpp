/*
Maximum Index

Question Link -->>

https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here

        vector<int> SufMax(n, 0);
        vector<int> PreMin(n, 0);

        int maxi = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            maxi = max(maxi, a[i]);
            SufMax[i] = maxi;
        }
        int mini = a[0];
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, a[i]);
            PreMin[i] = mini;
        }

        int ans = -1;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (PreMin[i] <= SufMax[j])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
            {

                i++;
            }
        }
        return ans;
    }
};