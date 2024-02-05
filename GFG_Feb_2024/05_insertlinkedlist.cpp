/*
Sorted insert for circular linked list

Question Link-->>
https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
*/

/* structure for a node */
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 

// This function should return head of
// the modified list
class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {
        // Your code here
        if (head == NULL)
        {
            Node *newnode = new Node(data);
            head = newnode;
            newnode->next = newnode;
            return head;
        }
        Node *temp = head;
        if (head->data > data)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *node = new Node(data);
            node->next = temp->next;
            temp->next = node;
            head = node;
        }
        else
        {
            while (temp->next->data < data && temp->next != head)
            {
                temp = temp->next;
            }
            Node *node = new Node(data);
            node->next = temp->next;
            temp->next = node;
        }

        return head;
    }
};