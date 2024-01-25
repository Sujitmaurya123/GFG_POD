/*
Shortest Prime Path

You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
num1 = 1033
num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach num2 from num1.
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
num1 = 1033
num2 = 1033
Output:
0
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers num1 and num2 as input parameters and returns the distance of the shortest path from num1 to num2. If it is unreachable then return -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1000<=num1,num2<=9999
num1 and num2 are prime numbers.


*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ischeck(int num)
    {
        if (num % 2 == 0)
            return false;
        if (num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int solve(int num1, int num2)
    {
        // code here

        queue<int> q;
        q.push(num1);
        int ans = 0;
        unordered_set<int> st;
        st.insert(num1);
        while (q.size())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int x = q.front();
                q.pop();
                if (x == num2)
                    return ans;
                for (int j = 0; j < 4; j++)
                {
                    string str = to_string(x);
                    for (int k = 0; k < 10; k++)
                    {
                        if (j == 0 && k < 9)
                        {
                            str[j] = (k + 1) + '0';
                        }
                        else if (j != 0)
                        {
                            str[j] = k + '0';
                        }

                        int num = stoi(str);
                        if (st.find(num) == st.end() && num <= 10000 && ischeck(num))
                        {
                            q.push(num);
                            st.insert(num);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};