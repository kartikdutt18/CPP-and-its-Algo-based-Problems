//https://leetcode.com/problems/squares-of-a-sorted-array/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstpositiveindex(vector<int> &A)
{
    int ans = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] >= 0 && ans == -1)
        {
            ans = i;
        }
        A[i] = A[i] * A[i];
    }
    return ans;
}
void merge(vector<int> &A, int e1, int e2)
{
    int i = 0, k = 0, j = e1;
    vector<int> temp(A.size(), 0);
    while (i < e1 && j < e2)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    while (j < e2)
    {
        temp[k++] = A[j++];
    }
    while (i < e1)
    {
        temp[k++] = A[i++];
    }

    for (int i = 0; i < e2; i++)
    {
        A[i] = temp[i];
    }
}
vector<int> sortedSquares(vector<int> A)
{
    if (A.size() == 0)
        return A;
    if (A[0] > 0)
    {
        firstpositiveindex(A);
        return A;
    }
    int ind = firstpositiveindex(A);

    if (ind == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    else
    {
        reverse(A.begin(), A.begin() + ind);

        merge(A, ind, A.size());
        return A;
    }
}