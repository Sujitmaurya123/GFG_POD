/*
Count the nodes at distance K from leaf

Question Link --->>>>

https://www.geeksforgeeks.org/problems/node-at-distance/1
*/
#include<bits/stdc++.h>
using namespace std;

struct Node

{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    // Function to return count of nodes at a given distance from leaf nodes.

    vector<vector<Node *>> paths;
    void solve(Node *root, vector<Node *> &temp)
    {
        if (!root)
            return;
        temp.push_back(root);
        if (!root->left && !root->right)
        {
            paths.push_back(temp);
        }
        solve(root->left, temp);
        solve(root->right, temp);
        temp.pop_back();
    }

    int printKDistantfromLeaf(Node *root, int k)
    {
        // Add your code here.
        vector<Node *> temp;
        solve(root, temp);
        unordered_set<Node *> result;
        for (vector<Node *> &path : paths)
        {
            int n = path.size();
            if (n > k)
            {
                result.insert(path[n - k - 1]);
            }
        }
        return result.size();
    }
};
