/*
Check if all leaves are at same level

Question Link-->>>

https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

*/

// The structure of the binary tree is as follows

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution
{
public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        // Your code here
        if (!root)
            return true;

        queue<pair<Node *, int>> qe;
        qe.push({root, 0});
        int same = -1;
        while (!qe.empty())
        {
            int size = qe.size();
            while (size--)
            {
                Node *node1 = qe.front().first;
                int level = qe.front().second;
                qe.pop();

                if (!node1->left && !node1->right)
                {
                    if (same == -1)
                    {
                        same = level;
                    }
                    else if (same != level)
                    {
                        return false;
                    }
                }
                if (node1->left)
                    qe.push({node1->left, level + 1});
                if (node1->right)
                    qe.push({node1->right, level + 1});
            }
        }
        return true;
    }
};