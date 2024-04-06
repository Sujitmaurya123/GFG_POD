/*
Count ways to N'th Stair

Question Link->
https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        // your code here
        //       long q=(long)n;
        //   return q/2+1;

        int t = n;
        long c = 0;
        while (t > 1)
        {
            t -= 2;
            c++;
        }
        return c + 1;
    }
};