/*
Question Link---->>>>
https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1
*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
//User function Template for C++

struct Node
{
    int data; // NOTE data is bool
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *rev(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *p = NULL, *q = NULL;
        while (head != NULL)
        {
            p = head;
            head = head->next;
            p->next = q;
            q = p;
        }
        return q;
    }
    // checking leading zeroes
    Node *check_0(Node *head)
    {
        if (head == NULL)
            return NULL;
        while (head != NULL && head->data == 0)
        {
            head = head->next;
        }
        return head;
    }
    // checking longest number
    bool check_head1(Node *head1, Node *head2)
    {
        bool first = false;
        Node *t1 = head1, *t2 = head2;
        while (head1 != NULL && head2 != NULL)
            head1 = head1->next, head2 = head2->next;
        if (head1)
            return true;
        if (head2)
            return false;
        while (t1 != NULL && t2 != NULL && t1->data == t2->data)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        if (t1 != NULL && t2 != NULL && t1->data > t2->data)
            return true;
        return false;
    }
    // Modification after Borrowing numbers
    Node *modify(Node *head)
    {
        Node *tmp = head;
        bool pre = true;
        while (head->next != NULL && head->data == 0)
        {
            head->data = 9, pre = false;
            head = head->next;
        }
        if (head)
            head->data -= 1, pre = true;
        return tmp;
    }
    // main code
    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        head1 = check_0(head1);
        head2 = check_0(head2);
        if (!check_head1(head1, head2))
            swap(head1, head2);
        head2 = rev(head2);
        head1 = rev(head1);
        Node *a = new Node(0);
        if (head1 == NULL && head2 == NULL)
            return a;
        Node *nn = new Node(-1);
        Node *res = nn;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data >= head2->data)
            {
                Node *tmp = new Node(head1->data - head2->data);
                nn->next = tmp;
                nn = nn->next;
            }
            else
            {
                if (head1->next->data > 0 && head1->next != NULL)
                {
                    head1->next->data -= 1;
                    Node *tmp = new Node((10 + head1->data) - head2->data);
                    nn->next = tmp;
                    nn = nn->next;
                }
                else if (head1->next->data == 0 && head1->next != NULL)
                {
                    head1->next = modify(head1->next);
                    Node *tmp = new Node((10 + head1->data) - head2->data);
                    nn->next = tmp;
                    nn = nn->next;
                }
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if (head1)
            nn->next = head1;
        if (head2)
            nn->next = head2;
        res = check_0(rev(res->next));
        if (res == NULL)
            return a;
        return res;
    }
};