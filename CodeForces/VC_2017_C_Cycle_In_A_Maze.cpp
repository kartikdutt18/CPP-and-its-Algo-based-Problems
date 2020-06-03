#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char>> board;
int n = 0, m = 0;
pair<int, int> curPos;
char stopChar = '*';
unordered_map<char, char> direction;


bool dfs(pair<int, int> source, string curString = "", int k = 0)
{
  if (source.first < 0 || source.second < 0 || 
      source.first >= n  || source.second >= m ||
      board[source.first][source.second] == stopChar
      || k < 0)
  {
    return false;
  }
  if (k == 0)
  {
    cout << curString;
    for (int i = curString.length() - 1; i>=0; i--)
    {
      cout << direction[curString[i]];
    }
    cout << endl;
    return true;
  }
   cout << source.first << " " << source.second << " " << curString << endl;
  if (source.first < n - 1 &&
      board[source.first + 1][source.second] != stopChar)
  {
    bool canGoDown = dfs({source.first + 1, source.second},
        curString + "D", k - 1);
    if (canGoDown)
      return true;
  }
  if (source.second > 0 &&
      board[source.first][source.second - 1] != stopChar)
  {
    bool canGoLeft = dfs({source.first, source.second - 1},
        curString + "L", k - 1);
    if (canGoLeft)
      return true;
  }
  if (source.second < m - 1 &&
      board[source.first][source.second + 1] != stopChar)
  {
    bool canGoRight = dfs({source.first, source.second + 1},
        curString + "R", k - 1);
    if (canGoRight)
      return true;
  }
  if (source.first > 0 &&
      board[source.first - 1][source.second] != stopChar)
  {
    bool canGoUp = dfs({source.first - 1, source.second},
        curString + "U", k - 1);
    if (canGoUp)
      return true;
  }
  return false;
}

int main()
{
  direction['L'] = 'R';
  direction['U'] = 'D';
  direction['R'] = 'L';
  direction['D'] = 'U';

  int k;
  cin >> n >> m >> k;
  board = vector<vector<char>>(n, vector<char>(m, '.'));
  curPos = {0, 0};
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      // cin >> board[i][j];
      if (board[i][j] == 'X')
        curPos = {i, j};
    }
  }
  if (k%2==1 || !dfs(curPos, "", k / 2))
    cout << "IMPOSSIBLE\n";

  return 0;
}