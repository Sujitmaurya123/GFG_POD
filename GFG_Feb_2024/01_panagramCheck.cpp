/*
Panagram Checking

Question Link ->>> https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1


Ques---             -----------------------------------------------

Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output:
1
Explanation:
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
s = "sdfs"
Output:
0
Explanation:
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
You do not have to take any input or print anything. You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a Panagram, or else it returns false.

Expected Time Complexity: O( |s| )
Expected Auxiliary Space: O(1)
|s| denotes the length of the input string.

Constraints:
1 ≤ |s| ≤ 104
Both Uppercase & Lowercase are considerable
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        vector<int> arr(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                char c = tolower(s[i]);
                arr[c - 'a'] = 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)
                return false;
        }
        return true;
    }
};