/*
Flatten BST to sorted list

Question Link -->>
https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
*/

// User function Template for C++

// Node of the binary search tree

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    void inorder(Node *curr, Node *&prev)
    {
        if (curr == NULL)
            return;

        inorder(curr->left, prev);
        prev->left = NULL;
        prev->right = curr;
        prev = curr;
        inorder(curr->right, prev);
        return;
    }
    Node *flattenBST(Node *root)
    {
        // code here
        Node *dummy = new Node(-1);
        Node *prev = dummy;

        inorder(root, prev);

        prev->left = NULL;
        prev->right = NULL;

        Node *ans = dummy->right;
        delete dummy;
        return ans;
    }
};