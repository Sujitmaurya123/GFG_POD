/*
Swap Array Elements

Question Link -->>
https://www.geeksforgeeks.org/problems/need-some-change/1

*/
// User function Template for C++

/*Function to swap array elements
 * arr : array input
 * n : number of elements in array
 */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swapElements(int arr[], int n)
    {

        // Your code here

        for (int i = 0; i < n - 2; i++)
        {
            swap(arr[i], arr[i + 2]);
        }
    }
};