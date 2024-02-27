/*
Play With OR

Question Link -->>

https://www.geeksforgeeks.org/problems/play-with-or5515/1

*/
#include<bits/stdc++.h>
using namespace std;

int *game_with_number(int arr[], int n)
{

    // Complete the function

    for (int i = 0; i < n - 1; i++)
    {
        int ans = arr[i] | arr[i + 1];
        arr[i] = ans;
    }
    return arr;
}