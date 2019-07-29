//https://leetcode.com/problems/interval-list-intersections/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<int>> ans;
    int i = 0;
    int j = 0;
    while (i < A.size() && j < B.size())
    {
        int s = max(A[i][0], B[j][0]);
        int e = min(A[i][1], B[j][1]);
        if (s <= e)
        {
            ans.push_back({s, e});
        }
        if (A[i][1] < B[j][1])
            i++;
        else
            j++;
    }
    return ans;
}