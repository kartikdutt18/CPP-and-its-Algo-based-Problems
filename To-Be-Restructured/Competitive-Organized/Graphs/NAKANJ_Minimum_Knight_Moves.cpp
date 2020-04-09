//https://www.spoj.com/problems/NAKANJ/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Chess
{
  vector<vector<int>> board;
  vector<vector<int>> visited;
  public:
  Chess()
  {
    board = vector<vector<int>>(8, vector<int>(8,0));
    visited = vector<vector<int>>(8, vector<int>(8, 0));
  }
  bool isValid(int x, int y)
  {
    return x>=0 && y>=0 && x<8 && y<8;
  }

  bool Visited(int x, int y)
  {
    return visited[x][y];
  }
  int bfs(pair<int,int> start, pair<int,int> end)
  {
    queue<pair<int,int>> q;
    q.push(end);
    vector<int> dx = {2, -2};
    vector<int> dy = {1, -1};

    while(!q.empty())
    {
      auto cur = q.front();
      q.pop();
      if(cur == start)
      {
        return board[cur.first][cur.second];
      }
      visited[cur.first][cur.second] = 1;
      for(int x = 0; x < 2; x++)
      {
        for(int y = 0; y < 2; y++)
        {
          if (isValid(cur.first + dx[x], cur.second + dy[y]) &&
              !Visited(cur.first + dx[x], cur.second + dy[y]))
          {
            q.push({cur.first + dx[x], cur.second + dy[y]});
            board[cur.first + dx[x]][cur.second + dy[y]] = board[cur.first][cur.second]+1;
          }
          if (isValid(cur.first + dy[y], cur.second + dx[x]) &&
              !Visited(cur.first + dy[y], cur.second + dx[x]))
          {
            q.push({cur.first + dy[y], cur.second + dx[x]});
            board[cur.first + dy[y]][cur.second + dx[x]] = board[cur.first][cur.second] + 1;
          }
        }
      }
    }
    return board[start.first][start.second];
  }
};

int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
    string s1,s2;
    cin>>s1>>s2;
    Chess c;
    cout << c.bfs({s1[0] - 'a', s1[1] - '1'}, {s2[0] - 'a', s2[1] - '1'}) << endl;
  }
  return 0;
}