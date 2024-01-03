/*
Smallest window containing 0, 1 and 2

Questions Link--> https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input:
S = 12121
Output:
-1
Explanation:
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        // Code here
        int zero = -1, one = -1, two = -1;
        int ans = 1e9;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '0')
                zero = i;
            if (S[i] == '1')
                one = i;
            if (S[i] == '2')
                two = i;

            if (zero != -1 and one != -1 and two != -1)
            {
                ans = min(ans, max(zero, max(one, two)) - min(zero, min(one, two)) + 1);
            }
        }

        if (ans == 1e9)
            return -1;
        return ans;
    }
};