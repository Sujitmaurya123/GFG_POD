/*
Largest Sum Subarray of Size at least K

Link--->  https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input :
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output :
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2}
Example 2:
Input :
n = 6
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output :
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
-105 <= a[i] <= 105
1 <= k <= n


*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        long long int ans = INT_MIN;
        long long int sum = 0;

        long long int last = 0;
        long long int j = 0;
        for (long long int i = 0; i < n; i++)
        {
            sum += a[i];
            if (i - j + 1 == k)
            {
                ans = max(ans, sum);
            }
            else if (i - j + 1 > k)
            {
                last += a[j];
                j++;
                if (last < 0)
                {
                    sum -= last;
                    last = 0;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};