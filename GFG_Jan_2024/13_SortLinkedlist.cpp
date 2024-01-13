/*
Insertion Sort for Singly Linked List

Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25
Output :
11 14 16 19 21 23 25 28 30 30
Explanation :
The resultant linked list is sorted.
Example 2:

Input :
N = 7
Linked List=19->20->16->24->12->29->30
Output :
12 16 19 20 24 29 30
Explanation :
The resultant linked list is sorted.
Your task:
You don't need to read input or print anything. Your task is to complete the function insertionSort() which takes the head of the linked list, sorts the list using insertion sort algorithm and returns the head of the sorted linked list.

Expected Time Complexity : O(n2)
Expected Auxiliary Space : O(1)

Constraints:
0 <= n <= 5*103
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
};

class Solution
{
public:
    Node *insertionSort(struct Node *head)
    {
        // code here
        Node *prev = head;
        Node *temp = head->next;
        Node *next;
        while (temp)
        {
            Node *first = head;
            next = temp->next;
            if (first->data > temp->data)
            {
                prev->next = temp->next;
                temp->next = head;
                head = temp;
                temp = next;
                continue;
            }
            else
            {
                while (first->next != temp && first->next->data < temp->data)
                {
                    first = first->next;
                }
                if (first->next->data >= temp->data && first->next != temp)
                {
                    prev->next = temp->next;
                    temp->next = first->next;
                    first->next = temp;
                }
                else
                {
                    prev = prev->next;
                }
            }
            temp = next;
        }
        return head;
    }
};