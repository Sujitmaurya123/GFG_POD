/*
Does array represent Heap

Question Link -->>

https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int i = 0;
        while (i < n)
        {
            int x = 2 * i + 1;
            if (x < n && arr[i] < arr[x])
            {
                return false;
            }
            x = 2 * i + 2;
            if (x < n && arr[i] < arr[x])
            {
                return false;
            }
            i++;
        }
        return true;
    }
};