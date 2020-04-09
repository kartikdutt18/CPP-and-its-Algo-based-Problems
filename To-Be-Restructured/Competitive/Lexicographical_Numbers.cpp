//https://leetcode.com/contest/warm-up-contest/problems/lexicographical-numbers/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> v;
    void bfs(long long n, int limit)
    {
        if (n == 0)
            return;
        queue<long long> q;
        if (n <= limit)
        {
            q.push(n);
        }
        while (!q.empty() && q.front() <= limit)
        {
            auto cur = q.front();
            v.push_back(cur);
            q.pop();
            for (int i = 0; i <= 9; i++)
            {
                if (cur * 10 + i <= limit)
                    q.push(cur * 10 + i);
                else
                    break;
            }
        }
    }
    void dfs(long long n, int limit)
    {
        if (n == 0)
            return;
        if (n > limit)
            return;
        if (v.size() && v.back() != n || v.size() == 0)
            v.push_back(n);
        for (int i = 0; i <= 9; i++)
        {
            if (n * 10 + i <= limit)
            {
                v.push_back(n * 10 + i);
                dfs(n * 10 + i, limit);
            }
        }
        return;
    }
    vector<int> lexicalOrder(int n)
    {
        for (long long i = 1; i <= 9; i++)
        {
            dfs(i, n);
        }
        return v;
    }
};