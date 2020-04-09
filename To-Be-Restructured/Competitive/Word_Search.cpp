//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dx = {-1, 1};
    bool dfshelper(vector<vector<char>> board, string target, int i, int j, int k)
    {

        if (k >= target.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        bool ans = false;

        for (auto l : dx)
        {

            if (l + i >= 0 && l + i < board.size() && target[k] == board[l + i][j] && !ans)
            {
                char temp = board[l + i][j];
                board[l + i][j] = '#';
                ans = ans || dfshelper(board, target, l + i, j, k + 1);
                board[l + i][j] = temp;
            }

            if (l + j >= 0 && l + j < board[0].size() && target[k] == board[i][l + j] && !ans)
            {

                char temp = board[i][l + j];
                board[i][j + l] = '#';
                ans = ans || dfshelper(board, target, i, l + j, k + 1);
                board[i][j + l] = temp;
            }
            if (ans)
                return ans;
        }
        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() == 0)
            return word == "";
        bool ans = false;
        for (int i = 0; i < board.size() && ans == false; i++)
        {
            for (int j = 0; j < board[0].size() && ans == false; j++)
            {
                if (board[i][j] == word[0])
                {
                    string a(1, word[0]);
                    board[i][j] = '#';
                    ans = ans || dfshelper(board, word, i, j, 1);
                    board[i][j] = a[0];
                }
            }
        }
        return ans;
    }
};