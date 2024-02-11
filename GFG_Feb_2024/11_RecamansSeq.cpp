/*
Recamans sequence
Question Link -->>
https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        // code here
        vector<int> ans(n);
        set<int> st;
        ans[0] = 0;
        st.insert(0);

        for (int i = 0; i < n; i++)
        {
            int x = ans[i - 1] - i;
            int y = ans[i - 1] + i;

            if (x < 0 || st.find(x) != st.end())
            {
                // if find in st me to
                ans[i] = y;
                st.insert(y);
            }
            else
            {
                ans[i] = x;
                st.insert(x);
            }
        }
        return ans;
    }
};