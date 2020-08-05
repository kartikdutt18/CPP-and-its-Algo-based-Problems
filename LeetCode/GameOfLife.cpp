#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  void gameOfLife(vector<vector<int>> &board)
  {
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[0].size(); j++)
      {
        int neighbour = CountNeighbours(board, i, j);
        if ((neighbour < 2 || neighbour > 3) && board[i][j])
          board[i][j] = -1;
        else if (neighbour == 3 && !board[i][j])
          board[i][j] = 2;
      }
    }

    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[0].size(); j++)
        if (board[i][j] == -1)
          board[i][j] = 0;
        else if (board[i][j] == 2)
          board[i][j] = 1;
    }
  }

private:
  bool isValid(vector<vector<int>> &board, int i, int j)
  {
    return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
  }

  int CountNeighbours(vector<vector<int>> &board, int x, int y)
  {
    vector<int> dx = {1, 0, -1};
    int ones = 0;
    for (int i = 0; i < dx.size(); i++)
    {
      for (int j = 0; j < dx.size(); j++)
      {
        if ((isValid(board, x + dx[i], y + dx[j])) && !(dx[i] == 0 && dx[j] == 0))
        {

          if (abs(board[x + dx[i]][y + dx[j]]) == 1)
            ones++;
        }
      }
    }

    return ones;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}