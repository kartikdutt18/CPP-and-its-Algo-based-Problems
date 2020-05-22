#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<pair<int, int>, bool> visited;
void dfs(int srcX, int srcY, int maxX, int maxY, int minX, int minY)
{
  if (visited[{srcX,srcY}])
    return;
  visited[{srcX, srcY}] = 1;
  vector<int> dx = {1, 0, -1 , 0};
  for(int i : dx)
  {
    if (!visited[{srcX + i, srcY + 1 - i}] &&
        srcX + i <= maxX && (srcY + 1 - i) <= maxY &&
        srcX + i >= minX && (srcY + 1 - i) >= minY)
    {
      dfs(srcX + i, srcY + 1 - i, maxX, maxY, minX, minY);
    }
  }
  return;
}
int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  int maxX = -1001, maxY = -1001, minX = 1001, minY = 1001;
  for(int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
    maxX 
  }

  return 0;
}