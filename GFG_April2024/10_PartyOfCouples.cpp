/*
Party of Couples

Question Link ->
https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

*/
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int findSingle(int n, int arr[])
    {
        // code here
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ arr[i];
        }
        return ans;
    }
};