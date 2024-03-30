/*
Minimum element in BST

https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
*/

// User function Template for C++

// Function to find the minimum element in the given BST.

#include<bits/stdc++.h>
using namespace std;


 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


class Solution
{
public:
    int minValue(Node *root)
    {
        // Code here
        if (root->left == NULL)
            return root->data;
        minValue(root->left);
    }
};