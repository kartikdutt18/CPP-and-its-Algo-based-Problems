//https://leetcode.com/problems/sum-of-even-numbers-after-queries/solution/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
{
    int even_sum = 0;
    vector<int> ans;

    for (int j = 0; j < A.size(); j++)
        if (A[j] % 2 == 0)
            even_sum += A[j];

    for (auto i : queries)
    {
        int temp = A[i[1]];
        A[i[1]] += i[0];
        if (temp % 2 == 0 && A[i[1]] % 2 == 0)
        {
            even_sum += i[0];
        }
        else if (temp % 2 == 0 && A[i[1]] % 2 != 0)
        {
            even_sum -= temp;
        }
        else if (temp % 2 != 0 && A[i[1]] % 2 == 0)
        {
            even_sum += A[i[1]];
        }
        ans.push_back(even_sum);
    }