/*
Power Set

Question Link -->.

https://www.geeksforgeeks.org/problems/power-set4302/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string s, int ind, string curr, vector<string> &ans)
    {
        if (ind == s.length())
        {
            if (curr.length() > 0)
            {
                ans.push_back(curr);
            }
            return;
        }

        // take
        curr.push_back(s[ind]);
        solve(s, ind + 1, curr, ans);

        // not take
        curr.pop_back();
        solve(s, ind + 1, curr, ans);

        return;
    }
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        // only fine substring

        //  vector<string>ans;

        //  for(int i=0;i<s.size();i++){

        //      for(int j=1;j<=s.size()-i;j++){
        //          string sk=s.substr(i,j);
        //          ans.push_back(sk);
        //      }
        //  }
        //  return ans;

        // subsequences

        string curr = "";
        vector<string> ans;
        int ind = 0;

        solve(s, ind, curr, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};