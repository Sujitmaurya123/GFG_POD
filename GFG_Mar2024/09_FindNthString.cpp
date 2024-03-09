/*
Find the N-th character
Question Link->
https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        // code herestring
        string temp = "";
        for (int i = 0; i < r; i++)
        {
            int j = 0;
            while (temp.length() <= n)
            {
                if (s[j] == '0')
                    temp += "01";
                else
                    temp += "10";
                j++;
            }
            s = temp;
            temp = "";
        }
        return s[n];
    }
};