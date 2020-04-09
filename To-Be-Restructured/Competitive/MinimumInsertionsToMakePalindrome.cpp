//https://leetcode.com/contest/weekly-contest-170/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minInsertionsHelper(string str, int n)
{
    int l, h, gap;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for (gap = 1; gap < n; gap++)
        for (l = 0, h = gap; h < n; ++l, ++h)
            dp[l][h] = (str[l] == str[h]) ? dp[l + 1][h - 1] : (min(dp[l][h - 1], dp[l + 1][h]) + 1);

    return dp[0][n - 1];
}
int minInsertions(string s)
{
    return minInsertionsHelper(s, s.length());
}