/*
Sum Of Products

Question Link ->
https://www.geeksforgeeks.org/problems/sum-of-products5049/1
*/
#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        // code here
        vector<int> bits(32, 0);

        for (int i = 0; i < n; i++)
        {
            int temp = arr[i];
            int j = 0;
            while (temp)
            {
                if (temp & 1)
                {

                    bits[j]++;
                }
                j++;
                temp >>= 1;
            }
        }
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            long long tm = bits[i];
            tm--;
            long long pair = (tm * (tm + 1)) / 2;
            ans += (pair * (long long)pow(2, i));
        }
        return ans;
    }
};