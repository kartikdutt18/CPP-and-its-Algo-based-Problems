#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> matrix(51, vector<int>(51, 0)), rowVec(51, vector<int>(51, 0)), colVec(51, vector<int>(51, 0));
int n, k, testNum;
bool solved(false);

void print()
{
  cout << "Case #" << testNum << ": "
       << "POSSIBLE" << endl;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
void Solution(int r, int c, int m)
{
  if (r == n && c == n + 1 && m == k && !solved)
  {
    solved = true;
    print();
    return;
  }
  else if (r > n)
  {
    return;
  }
  else if (c > n)
  {
    Solution(r + 1, 1, m);
  }
  for (int i = 1; i <= n && !solved; ++i)
  {
    if (!rowVec[r][i] && !colVec[c][i])
    {
      rowVec[r][i] = colVec[c][i] = true;
      if (r == c)
      {
        m += i;
      }
      matrix[r][c] = i;
      Solution(r, c + 1, m);
      rowVec[r][i] = colVec[c][i] = false;
      if (r == c)
      {
        m -= i;
      }
      matrix[r][c] = 0;
    }
  }
}

int main()
{
  int T;
  cin >> T;
  for (testNum = 1; testNum <= T; testNum++)
  {
    cin>>n>>k;
    Solution(1,1,0);
    if(!solved)
    {
      cout<<"Case #"<<testNum<< ": "<<"IMPOSSIBLE"<<endl;
    }
    solved = false;
  }
  return 0;
}