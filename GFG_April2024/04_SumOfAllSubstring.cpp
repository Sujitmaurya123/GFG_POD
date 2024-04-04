/*
Sum of all substrings of a number

Question Link->
https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {

        // your code here
        long long mod = 1e9 + 7;
        int n = s.size();

        long long prev = 0, curr = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            curr = (s[i] - '0') * (i + 1) + prev * 10;
            curr %= mod;
            ans += curr;
            ans %= mod;
            prev = curr;
        }
        return ans;
    }
};