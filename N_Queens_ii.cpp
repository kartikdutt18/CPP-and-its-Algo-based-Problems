//https://leetcode.com/problems/n-queens-ii/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bitset<30> d1;
bitset<30> d2;
bitset<30> c;

int ans = 0;
void Queenhelper(int i, int n)
{
    if (i == n)
    {
        ans++;

        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (c[j] == 0 && d2[i + j] == 0 && d1[i - j - 1 + n] == 0)
        {
            c[j] = d2[i + j] = d1[i - j - 1 + n] = 1;
            Queenhelper(i + 1, n);
            c[j] = d2[i + j] = d1[i - j - 1 + n] = 0;
        }
    }
}

int totalNQueens(int n)
{

    Queenhelper(0, n);
    return ans;
}