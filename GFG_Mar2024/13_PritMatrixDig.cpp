/*
Printing Matrix Diagonal Elements
Question Link->
https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

*/

/*You are required to complete this method */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        // Your code here
        int n = mat.size();
        vector<int> ans;
        bool f = 1;
        for (int i = 0; i <= 2 * (n - 1); i++)
        {
            if (f)
            {
                for (int j = i; j >= 0; j--)
                    if (j < n && j >= 0 && i - j < n && i - j >= 0)
                        ans.push_back(mat[j][i - j]);
            }
            else
            {
                for (int j = 0; j <= i; j++)
                    if (j < n && j >= 0 && i - j < n && i - j >= 0)
                        ans.push_back(mat[j][i - j]);
            }
            f = !f;
        }
        return ans;
    }
};