/*
Count all Possible Path

Question Link -->>

https://www.geeksforgeeks.org/problems/castle-run3644/1

*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPossible(vector<vector<int>> paths)
    {
        // Code here

        // int n=paths.size();

        // for(int i=0;i<n;i++){
        // int ct=0;
        // for(int j=0;j<n;j++){

        //     if(paths[i][j]==1){
        //         ct++;
        //     }

        // }

        // if(ct%2==1){
        //     return 0;
        // }

        // }
        // return 1;

        for (auto i : paths)
        {
            if (accumulate(i.begin(), i.end(), 0) % 2 != 0)
                return false;
        }
        return true;
    }
};