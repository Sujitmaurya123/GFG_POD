/*
Largest Number formed from an Array

Question Link -->>
https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
*/

// User function template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return (a + b) > (b + a);

        // string ab=a.append(b);
        // string ba=b.append(a);

        // return ab.compare(ba)>0 ?1:0;
    }
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(int n, vector<string> &arr)
    {
        // code here

        sort(arr.begin(), arr.end(), cmp);
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }
        return ans;
    }
};