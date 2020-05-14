#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int t;
  cin >> t;
  vector<vector<int>> v(3, vector<int>(t, 0));
  for (int i = 0; i < 3*t; i++)
  {
    cin >> v[i % 3][i / 3];
  }

  if (accumulate(v[1].begin(), v[1].end(), 0) == 0 &&
      accumulate(v[2].begin(), v[2].end(), 0) == 0 &&
      accumulate(v[0].begin(), v[0].end(), 0) == 0)
    cout << "YES\n";
  else
  {
    cout << "NO\n";
  }
  return;
}

int main()
{
  solve();
  return 0;
}
