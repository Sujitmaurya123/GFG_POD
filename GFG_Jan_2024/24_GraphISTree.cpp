/*
Check if a given graph is tree or not

You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output:
1
Explanation:
Every node is reachable and the graph has no loops, so it is a tree
Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output:
0
Explanation:
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 2*105
0 <= M <= 2*105


*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(vector<vector<int>> &adjlist, vector<int> &visi, int n, int m, int node, int parent)
    {
        visi[node] = 1;

        // traveral all neighhour
        for (auto newnode : adjlist[node])
        {
            if (!visi[newnode])
            {

                if (!isCycle(adjlist, visi, n, m, newnode, node))
                {
                    return false;
                }
            }
            else if (parent != newnode)
            {
                return false;
            }
        }
        return true;
    }
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        // code here
        vector<vector<int>> adjlist(n, vector<int>());
        // make adjlist of graph
        for (int i = 0; i < m; i++)
        {
            adjlist[adj[i][0]].push_back(adj[i][1]);
            adjlist[adj[i][1]].push_back(adj[i][0]);
        }

        vector<int> visi(n, 0);

        bool res = isCycle(adjlist, visi, n, m, 0, -1);
        for (int i = 0; i < n; i++)
        {
            if (!visi[i])
                return false;
        }
        return res;
    }
};