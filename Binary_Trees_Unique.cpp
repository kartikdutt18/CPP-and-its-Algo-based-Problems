//https://leetcode.com/problems/unique-binary-search-trees/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    long int nc2n = 1;
    for (int i = 0; i < n; i++)
    {
        nc2n *= (2 * n - i);
        nc2n /= (i + 1);
    }

    return (int)(nc2n / (n + 1));
}
