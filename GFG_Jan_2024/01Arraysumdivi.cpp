/*
Array Pair Sum Divisibility Problem

Question Link --->  https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :

Input :
nums = [9, 5, 7, 3]
k = 6
Output:
True
Explanation:
{(9, 3), (5, 7)} is a
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.
Example 2:

Input :
nums = [4, 4, 4]
k = 4
Output:
False
Explanation:
You can make 1 pair at max, leaving a single 4 unpaired.


Expected Time Complexity: O(n)
Expected Space Complexity : O(n)

Constraints:
1 <= length( nums ) <= 105
1 <= numsi <= 105
1 <= k <= 105

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        int n = nums.size();
        if (n % 2 != 0)
            return false;
        vector<int> mp(k + 1, 0);
        for (auto x : nums)
        {
            x %= k;
            mp[x]++;
            mp[k - x]--;
        }
        for (int i = 1; i < k; i++)
        {
            if (mp[i] > 0)
                return false;
        }
        return true;
    }
};