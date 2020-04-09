//https://leetcode.com/problems/unique-paths-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &board)
{
    vector<vector<long long int>> dp(board.size(), vector<long long int>(board[0].size(), 0));
    dp[0][0] = 1 - board[0][0];
    for (int i = 1; i < board.size(); i++)
        dp[i][0] = dp[i - 1][0] != 0 && board[i][0] != 1 ? 1 : 0;
    for (int i = 1; i < board[0].size(); i++)
        dp[0][i] = dp[0][i - 1] != 0 && board[0][i] != 1 ? 1 : 0;
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 1; j < board[0].size(); j++)
        {
            dp[i][j] = board[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[board.size() - 1][board[0].size() - 1];
}