/*
All Unique Permutations of an array

Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input:
n = 3
arr[] = {1, 2, 1}
Output:
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input:
n = 2
arr[] = {4, 5}
Output:
Only possible 2 unique permutations are
4 5
5 4
Your Task:
You don't need to read input or print anything. You only need to complete the function uniquePerms() that takes an integer n, and an array arr of size n as input and returns a sorted list of lists containing all unique permutations of the array.

Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)

Constraints:
1 ≤ n ≤ 9
1 ≤ arri ≤ 10
*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> st;
    void solve(vector<int> &arr, int n, int i)
    {
        if (i == n)
        {
            st.insert(arr);
            return;
        }
        for (int j = i; j < n; j++)
        {
            swap(arr[i], arr[j]);
            solve(arr, n, i + 1);
            swap(arr[i], arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        // code here
        // sort(arr.begin(),arr)
        solve(arr, n, 0);
        vector<vector<int>> res;
        for (auto j : st)
        {
            res.push_back(j);
        }
        return res;
    }
};