#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  reverse(v.begin(), v.end());
  reverse(v.begin(), v.begin() + n - k);
  reverse(v.begin() + n - k, v.end());
  for (int i = 0; i < n; i++)
    cout << v[i] << " ";
  cout << endl;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}