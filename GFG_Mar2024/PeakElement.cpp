/*
Peak Element

Question Link -->>
https://www.geeksforgeeks.org/problems/peak-element/1

*/

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        // Your code here
        int l = 0, h = n - 1;
        int mid;

        while (l < h)
        {
            mid = l + (h - l) / 2;

            if (arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return l;
    }
};