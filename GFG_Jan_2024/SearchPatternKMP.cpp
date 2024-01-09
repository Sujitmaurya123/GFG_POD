/*
Search Pattern (KMP-Algorithm)

90% Refund available on all premium courses
Discover How

banner
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices.
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output:
1 9
Explanation:
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9.
Example 2:

Input:
txt = "abesdu"
pat = "edu"
Output:
-1
Explanation:
There's not substring "edu" present in txt.
Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt.

Expected Time Complexity: O(|txt|).
Expected Auxiliary Space: O(|txt|).

Constraints:
1 ≤ |txt| ≤ 105
1 ≤ |pat| < |S|
Both the strings consists of lowercase English alphabets.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // code here
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < txt.size())
        {
            if (txt[i] == pat[j])
            {

                int last = i;
                while (txt[i] == pat[j] && j < pat.length() && i < txt.size())
                {
                    i++;
                    j++;
                }

                if (j == pat.length())
                {
                    ans.push_back(last + 1);
                    j = 0;
                    i = last + 1;
                }
                else
                {
                    j = 0;
                    i = last + 1;
                }
            }
            else
            {
                i++;
            }
        }
        if (ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};