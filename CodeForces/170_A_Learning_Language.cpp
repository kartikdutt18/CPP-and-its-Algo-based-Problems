#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, list<int>> LanguageMap;
unordered_map<int, list<int>> EmployeeMap;
vector<int> visited;

void dfs(int src)
{
  if (visited[src])
    return;
  visited[src] = 1;
  for (int language : EmployeeMap[src])
  {
    for (int employee : LanguageMap[language])
    {
      if (!visited[employee])
        dfs(employee);
    }
  }
  return;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int zeroLangs = 0;
  for(int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++)
    {
      int t;
      cin >> t;
      LanguageMap[t].push_back(i);
      EmployeeMap[i].push_back(t);
    }
    zeroLangs += (k == 0);
  }
  int ans = 0;
  visited = vector<int>(n, 0);

  for(int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      ans++;
      dfs(i);
    }
  }
  cout << max(ans - 1, zeroLangs) << endl;
  return 0;
}