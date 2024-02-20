/*
Words Break

Question Link -->>

https://www.geeksforgeeks.org/problems/word-break1352/1

*/

// User function template for C++

// s : given string to search
// dictionary : vector of available strings

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(string s, unordered_map<string, int> &mp, int index)
    {
        if (index >= s.size())
            return true;

        for (int i = index; i < s.size(); i++)
        {
            string skm = s.substr(index, i - index + 1);

            if (mp.find(skm) != mp.end())
            {
                if (solve(s, mp, i + 1))
                    return true;
            }
        }
        return false;
    }

public:
    int wordBreak(int n, string s, vector<string> &dictionary)
    {
        // code here

        unordered_map<string, int> mp;

        for (auto sk : dictionary)
        {
            mp[sk]++;
        }

        if (solve(s, mp, 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};