/*
Paths from root with a specified sum

Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path not necessarily end on a leaf node.

Example 1:

Input :
sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15
        /  \     /  \
       6    7   8    9

Output :
1 3 4
Explanation :
Sum of path 1, 3, 4 = 8.
Example 2:

Input :
sum = 38
Input tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15
Explanation :
Sum of path 10, 28 = 38 and
Sum of path 10, 13, 15 = 38.
Your task :
You don't have to read input or print anything. Your task is to complete the function printPaths() that takes the root of the tree and sum as input and returns a vector of vectors containing the paths that lead to the sum.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N2)

Your Task :
1 <= N <= 2*103
-103 <= sum, Node.key <= 103


*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};


    class Solution
{
public:
    void solve(Node *root, int sum, vector<int> temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        temp.push_back(root->key);
        if (sum - root->key == 0)
        {
            ans.push_back(temp);
        }
        solve(root->left, sum - root->key, temp, ans);
        solve(root->right, sum - root->key, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;

        solve(root, sum, temp, ans);

        return ans;
    }
};