#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

  int s, n, x, y;
  cin >> s >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    if (v[i].first >= s)
    {
      cout << "NO";
      return 0;
    }
    s += v[i].second;
  }
  cout << "YES";
  return 0;
}