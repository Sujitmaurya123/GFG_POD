/*
First Occus Elements in Array

Question Link -->>
https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            if (mp[a[i]] == k)
            {
                return a[i];
            }
        }

        return -1;
    }
};