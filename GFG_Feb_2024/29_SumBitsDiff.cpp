/*
Sum Of Bits Differents

Question Link -->
https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

*/

// User function template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumBitDifferences(int arr[], int n)
    {
        // code here
        // O(n^2)  TC

        // int sum=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=0;i<n-1;j++){
        //         sum+= __builtin_popcount(arr[i]^arr[j]);
        //     }

        // }
        // return sum;

        long long ans = 0;

        for (int i = 0; i < 32; i++)
        {

            long long count = 0;

            for (int j = 0; j < n; j++)
            {
                // at each position find the set bit
                if (arr[j] & (1 << i))
                    count++;
            }
            ans += count * (n - count) * 2;
        }
        return ans;
    }
};