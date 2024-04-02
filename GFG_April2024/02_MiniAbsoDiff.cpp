/*
Minimum Absolute Difference In BST
Question Link->
https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
*/

//The Node structure is defined as
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

};


class Solution
{
    void inorder(Node *root, int &prev, int &mini)
    {
        // base case
        if (root == NULL)
            return;

        inorder(root->left, prev, mini);
        if (prev == -1)
        {
            prev = root->data;
        }
        else
        {
            mini = min(mini, root->data - prev);
            prev = root->data;
        }
        inorder(root->right, prev, mini);
    }

public:
    int absolute_diff(Node *root)
    {
        // Your code here
        int prev = -1, mini = INT_MAX;

        inorder(root, prev, mini);
        return mini;
    }
};