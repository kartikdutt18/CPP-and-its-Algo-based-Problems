//https://leetcode.com/problems/find-the-celebrity/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool knows(int a, int b);

int findCelebrity(int n)
{
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int call = knows(i, j);
            indegree[j] += call;
            outdegree[i] += call;
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == n && outdegree[i] == 1)
            ans = i;
    }
    return ans;
}