#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> v(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    for (int j : {a, b, c})
    {
      if (i - j >= 0 && (v[i-j]>0 || i == j))
        v[i] = max(v[i], v[i - j] + 1);
    }
  }

  cout << v[n] << endl;
  return 0;
}