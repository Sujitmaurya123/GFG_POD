/*
Decimal Equivalent of Binary Linked List

Question Link--->>  https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1


Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
The significance of the bits decreases with the increasing index in the linked list.
An empty linked list is considered to represent the decimal value 0.

Since the answer can be very large, answer modulo 109+7 should be printed.

Example 1:
Input:
n = 3
Linked List = {0, 1, 1}
Output:
3
Explanation:
0*22 + 1*21 + 1*20 =  1 + 2 + 0 = 3
Example 2:
Input:
n = 4
Linked List = {1, 1, 1, 0}
Output:
14
Explanation:
1*23 + 1*22 + 1*21 + 0*20 =  8 + 4 + 2 + 0 = 14
Your Task:
You do not have to take any input or print anything. Complete the function decimalValue() which takes a head node of a linked list as an input parameter and returns decimal representation of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 100
Data of each node is either 0 or 1
*/

/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; 

class Solution
{
    const long long unsigned int MOD = 1000000007;

public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list

    long long unsigned int decimalValue(Node *head)
    {
        // Your Code Here
        string s = "";
        long long unsigned int ans = 0;
        long long unsigned int power = 1;
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            n++;
            s += char(temp->data);
            temp = temp->next;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int x = int(s[i]);
            ans = ans + x * power;
            ans = ans % MOD;
            power = (power * 2) % MOD;
        }
        return ans % MOD;
    }
};
