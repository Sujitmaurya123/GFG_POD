/*
Reverse Bits
Question Link ->
https://www.geeksforgeeks.org/problems/reverse-bits3556/1
*/
#include<bits/stdc++.h>
class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        long long int ans = 0;
        int i = 31;

        while (x)
        {
            ans += (long long)pow(2, i) * (x & 1);
            x >>= 1;
            i--;
        }
        return ans;
    }
};