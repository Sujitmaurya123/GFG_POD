/*
Merge 2 sorted linked list in reverse order

Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104


*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
    class Solution
{
public:
    struct Node *reverse(Node *head)
    {

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        Node *head = new Node();
        Node *temp = head;

        Node *curr1 = node1;
        Node *curr2 = node2;

        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->data < curr2->data)
            {
                temp->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                temp->next = curr2;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }

        while (curr1 != NULL)
        {
            temp->next = curr1;
            curr1 = curr1->next;
            temp = temp->next;
        }

        while (curr2 != NULL)
        {
            temp->next = curr2;
            curr2 = curr2->next;
            temp = temp->next;
        }

        return reverse(head->next);
    }
};