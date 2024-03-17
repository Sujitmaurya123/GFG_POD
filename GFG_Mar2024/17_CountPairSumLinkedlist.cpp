/*
Count Pairs whose sum is equal to X
Question Link ->

https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // your task is to complete this function
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        // Code here

        set<int> st;

        Node *tm = head1;
        while (tm)
        {
            st.insert(tm->data);
            tm = tm->next;
        }

        int ans = 0;
        tm = head2;

        while (tm)
        {
            if (st.find(x - tm->data) != st.end())
            {

                ans++;
            }
            tm = tm->next;
        }
        return ans;
    }
};