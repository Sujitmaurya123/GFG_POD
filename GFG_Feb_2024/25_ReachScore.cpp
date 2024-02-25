/*
Reach a given score

Question Linkc-->>

https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    long long int count(long long int n)
    {
        

        vector<long long int> v(n + 1, 0);
        v[0] = 1;

        for (int i = 3; i <= n; i++)
        {
            v[i] += v[i - 3];
        }
        for (int i = 5; i <= n; i++)
        {
            v[i] += v[i - 5];
        }
        for (int i = 10; i <= n; i++)
        {
            v[i] += v[i - 10];
        }
        return v[n];
    }
};