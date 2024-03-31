/*
Closest Neighbour in BST

Question Link->
https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
*/

// User function Template for C++

//Structure of the Node of the BST is as
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

/*
   'N' is the element
   'size' is the total element in BST
  */

class Solution
{
public:
    void inorder(Node *root, int n, int &ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, n, ans);
        if (root->key <= n)
        {
            ans = root->key;
        }
        inorder(root->right, n, ans);
    }
    int findMaxForN(Node *root, int n)
    {
        // code here

        int ans = -1;

        inorder(root, n, ans);
        return ans;
    }
};