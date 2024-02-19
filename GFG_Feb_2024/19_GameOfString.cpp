/*
Game Of String

Question Link -->>

https://www.geeksforgeeks.org/problems/game-with-string4100/1

*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here

        unordered_map<char, int> mp;

        for (auto sk : s)
        {
            mp[sk]++;
        }

        priority_queue<int> pq;

        for (auto s : mp)
        {
            pq.push(s.second);
        }

        for (int i = 0; i < k; i++)
        {
            int b = pq.top();
            pq.pop();
            b--;
            if (b > 0)
            {
                pq.push(b);
            }
        }

        int ans = 0;

        while (!pq.empty())
        {
            ans += pq.top() * pq.top();
            pq.pop();
        }
        return ans;
    }
};