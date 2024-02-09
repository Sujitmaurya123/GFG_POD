/*
Check for Children Sum Property in a Binary Tree

Question Link -->>>>

https://www.geeksforgeeks.org/problems/children-sum-parent/1


*/

//Complete the function below
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        // Add your code here
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;

        int sum = 0;
        if (root->left != NULL)
            sum += root->left->data;
        if (root->right != NULL)
            sum += root->right->data;

        return (root->data == sum && isSumProperty(root->left) && isSumProperty(root->right));
    }
};