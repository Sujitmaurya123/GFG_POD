/*
Euler Circuit in an Undirected Graph

Question Link ->
https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEularCircuitExist(int v, vector<int> adj[])
    {
        // Code here

        // for(int i=0;i<v;i++){
        //     if(int(adj[i].size())%2==1)return false;
        // }
        // return true;

        vector<int> indeg(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};