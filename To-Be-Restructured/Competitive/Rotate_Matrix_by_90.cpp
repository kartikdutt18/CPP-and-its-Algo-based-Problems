//https://leetcode.com/problems/rotate-image/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    int j = 0;
    for (auto i : matrix)
    {
        reverse(i.begin(), i.end());
        matrix[j++] = i;
    }
}