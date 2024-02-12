/*
Recursive sequence


Question Link -->>

https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MOD 1000000007
    long long sequence(int n)
    {
        // code here
        long long ans = 1;
        long long e = 2;

        for (int i = 2; i <= n; i++)
        {
            long long c = 1;

            for (int j = 1; j <= i; j++)
            {
                c = (c * e) % MOD;
                e++;
            }
            ans = (ans + c) % MOD;
        }
        return ans;
    }
};