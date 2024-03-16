/*
Delete without head pointer

Question Link ->
https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;


class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
        // Your code here

        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
};