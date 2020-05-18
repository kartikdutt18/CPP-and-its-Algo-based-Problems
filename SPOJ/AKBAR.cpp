#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
  int n, m, r;
  unordered_map<int, list<int>> adjList;
  vector<int> visited;
  vector<ll> parent;
  bool ans;
  public:
  bool dfs(ll city, ll level, ll cParent)
  {
    if (level < 0)
      return false;
    //cout << city << " " << level << " " << cParent << endl;
    if (visited[city]>0 && parent[city] != cParent)
    {
      return false;
    }
    if (level == 0)
    {
      visited[city]++;
      parent[city] = cParent;
      return true;
    }
    visited[city]++;
    parent[city] = cParent;
    bool flag = true;
    for (ll child : adjList[city])
    {
      flag = flag & dfs(child, level - 1, cParent);
    }
    return flag;
  }

  void solve()
  {
    ans = true;
    cin >> n >> r >> m;
    visited = vector<int>(n + 1, 0);
    parent = vector<ll>(n + 1, -1);
    for(int i = 0; i < r; i++)
    {
      ll a, b;
      cin >> a >> b;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
      ll soldier, strength;
      cin >> soldier >> strength;
      ans = ans and dfs(soldier, strength, soldier);
      if (!ans)
        break;
    }
    if (ans)
      cout << "Yes \n";
    else
      cout << "No \n";
  }
};

int main() {
  ll t;
  cin >> t;
  while(t--)
  {
    Solution s;
    s.solve();
  }
  return 0;
}