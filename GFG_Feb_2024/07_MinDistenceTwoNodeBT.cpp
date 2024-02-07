/*
Min distance between two given nodes of a Binary Tree

Question Link --->>>

https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
*/

// A binary tree node


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution
{
private:
    Node *findLCA(Node *currNode, int a, int b)
    {

        if (currNode == NULL)
        {
            return NULL;
        }

        if ((currNode->data == a) || (currNode->data == b))
        {
            return currNode;
        }

        Node *leftAns = findLCA(currNode->left, a, b);
        Node *rightAns = findLCA(currNode->right, a, b);

        if (leftAns == NULL && rightAns == NULL)
        {
            return NULL;
        }

        if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }

        if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }

        return currNode;
    }

    int findDist(Node *currNode, int nodeVal)
    {

        if (currNode == NULL)
        {
            return -1;
        }

        if (currNode->data == nodeVal)
        {
            return 0;
        }

        int leftAns = findDist(currNode->left, nodeVal);
        if (leftAns >= 0)
        {
            return leftAns + 1;
        }

        int rightAns = findDist(currNode->right, nodeVal);
        if (rightAns >= 0)
        {
            return rightAns + 1;
        }

        return -1;
    }

public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *LCA = findLCA(root, a, b);
        int distFromAtoLCA = findDist(LCA, a);
        int distFromBtoLCA = findDist(LCA, b);

        return (distFromAtoLCA + distFromBtoLCA);
    }
};