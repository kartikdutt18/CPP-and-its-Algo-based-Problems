//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largestSumAfterKNegations(vector<int> &A, int K)
{
    sort(A.begin(), A.end());
    int sum = 0, n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0 && K)
        {
            sum += A[i] * -1;
            A[i] *= -1;
            K--;
        }
        else
            sum += A[i];
    }
    sort(A.begin(), A.end());
    if (K && K % 2)
    {
        if (A[0])
        {
            sum -= 2 * A[0];
        }
        else
            sum += 2 * A[0];
    }
    return sum;
}