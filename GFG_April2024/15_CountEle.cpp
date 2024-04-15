/*
Count the Elements

Question Link ->
https://www.geeksforgeeks.org/problems/count-the-elements1529/1
*/
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q)
    {
        // Your code goes here;
        vector<int> ans;
        int m = 0;

        for (int i = 0; i < n; i++)
            m = max(m, max(a[i], b[i]));

        vector<int> v(m + 1, 0);

        for (int i = 0; i < n; i++)
            v[b[i]]++;

        for (int i = 1; i <= m; i++)
            v[i] += v[i - 1];

        for (int i = 0; i < q; i++)
            ans.push_back(v[a[query[i]]]);

        return ans;
    }
};