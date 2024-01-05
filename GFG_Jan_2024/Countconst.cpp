/*
Count possible ways to construct buildings

There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

Example 1:

Input: N = 1
Output: 4
Explanation:
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.
Example 2:

Input: N = 3
Output: 25
Explanation:
Possible ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space. Pairing up with
possibilities on the other side of the road,
total possible ways are 25.



Expected Time Complexity: O(N)
Expected Space Complexity: O(N)


Constraints:
1 <= N <= 100000
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long fibonacci(int n)
    {
        const int mod_value = 1000000007;
        if (n <= 1)
        {
            return n;
        }

        long long t1 = 0, t2 = 1, nextTerm;

        for (int i = 2; i <= n; ++i)
        {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            nextTerm %= mod_value;
            t1 %= mod_value;
            t2 %= mod_value;
        }

        return t2;
    }
    int TotalWays(int N)
    {
        // Code here
        const int mod_value = 1000000007;
        long long ans = fibonacci(N + 2);
        return (ans * ans) % mod_value;
    }
};