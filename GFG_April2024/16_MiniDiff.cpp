/*
Minimize the Difference

Question Link ->
https://www.geeksforgeeks.org/problems/minimize-the-difference/1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        // code here

        vector<int> rightmn(n, 0), rightmx(n, 0);
        rightmx[n - 1] = arr[n - 1];
        rightmn[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            rightmx[i] = max(rightmx[i + 1], arr[i]);
            rightmn[i] = min(rightmn[i + 1], arr[i]);
        }
        int i = 0, j = k - 1, mn = INT_MAX, mx = INT_MIN, ans = INT_MAX;

        while (j < n)
        {
            if (i != 0)
            {
                mx = max(mx, arr[i - 1]);
                mn = min(mn, arr[i - 1]);
            }
            int temp1 = mn, temp2 = mx;
            if (j != n - 1)
            {
                temp1 = min(temp1, rightmn[j + 1]);
                temp2 = max(temp2, rightmx[j + 1]);
            }
            ans = min(ans, abs(temp2 - temp1));
            i++;
            j++;
        }
        return ans;
    }
};