/*
Distinct occurrences

Question Link -->>

https://www.geeksforgeeks.org/problems/distinct-occurrences/1

*/

/*You are required to complete this method*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int subsequenceCount(string S, string T)
    {
        // Your code here
        int n = S.length();
        int m = T.length();
        vector<int> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (S[i - 1] == T[j - 1])
                    prev[j] = (prev[j - 1] % mod + prev[j] % mod) % mod;
                else
                    prev[j] = prev[j] % mod;
            }
        }
        return prev[m] % mod;
    }
};
