/*
Count Sum in Matrix
Question Link->

https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

*/

// User function template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        // Your code goes here
        int ans = 0;
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
        while (r1 < n and r2 >= 0)
        {
            int ele = mat1[r1][c1] + mat2[r2][c2];
            if (ele == x)
            {
                ans++, c1++, c2--;
            }
            else if (ele < x)
            {
                c1++;
            }
            else if (ele > x)
            {
                c2--;
            }
            // Interesting things
            if (c1 == n)
            {
                c1 = 0;
                r1++;
            }
            if (c2 == -1)
            {
                c2 = n - 1;
                r2--;
            }
        }
        return ans;
    }
};