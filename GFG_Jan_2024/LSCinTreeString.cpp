/*
LSC In Three String

Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor",
C = "geeksforgeeks"
Output: 5
Explanation:
"geeks"is the longest common
subsequence with length 5.
Example 2:

Input:
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation:
There's no subsequence common
in all the three strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.



*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        // your code here
        vector<vector<vector<int>>> tab(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                for (int k = 1; k <= n3; k++)
                {
                    if (A[i - 1] == B[j - 1] and A[i - 1] == C[k - 1])
                        tab[i][j][k] = 1 + tab[i - 1][j - 1][k - 1];
                    else
                    {
                        int res = max(tab[i - 1][j][k],
                                      max(tab[i][j - 1][k], tab[i][j][k - 1]));
                        tab[i][j][k] = res;
                    }
                }
            }
        }
        return tab[n1][n2][n3];
    }
};