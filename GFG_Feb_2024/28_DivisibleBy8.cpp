/*
Check if a number is divisible by 8

Question Link -->>
https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        // code here
        int n = s.size();
        int num = 0;
        if (n < 3)
        {
            num = stoi(s);
        }
        else
        {
            num = stoi(s.substr(n - 3, 3));
        }
        if (num % 8 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};