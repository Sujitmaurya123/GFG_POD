/*
Kth common ancestor in BST
Question Link->
https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

*/
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
    Node *findAncestor(Node *root, int x, int y)
    {
        if (!root)
            return root;

        int d = root->data;
        if (d == x || d == y)
        {
            return root;
        }
        else if (d > x && d > y)
        {
            return findAncestor(root->left, x, y);
        }
        else if (d < x && d < y)
        {
            return findAncestor(root->right, x, y);
        }
        else
        {
            return root;
        }
    }

public:
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        // your code goes here
        // FINDING THE FIRST ANCESTOR
        Node *firstAncestor = findAncestor(root, x, y);

        // CREATING TWO POINTERS SLOW AND FAST INITIALLY BOTH POINTING TO ROOT
        Node *slow = root;
        Node *fast = root;

        // MOVING THE FAST POINTER k-1 STEPS AHEAD OF THE SLOW POINTER
        for (int i = 0; i < k - 1; i++)
        {
            if (fast->data == firstAncestor->data)
                return -1;
            if (fast->data < firstAncestor->data)
                fast = fast->right;
            else
                fast = fast->left;
        }

        // MOVING THE SLOW POINTER TOWARDS THE FIRST ANCESTOR UNTIL THE FAST POINTER REACHES THE FIRST ANCESTOR
        while (fast->data != firstAncestor->data)
        {
            if (fast->data < firstAncestor->data)
                fast = fast->right;
            else
                fast = fast->left;

            if (slow->data < firstAncestor->data)
                slow = slow->right;
            else
                slow = slow->left;
        }
        // FINALLY RETURNING THE SLOW POINTER
        return slow->data;
    }
};
