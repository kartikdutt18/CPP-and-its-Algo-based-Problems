#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  string s;
  while (s.length() == 0)
    getline(cin, s);
  if (s.length() > 10)
    cout << s[0] << s.length() - 2 << s.back() << endl;
  else
  {
    cout << s << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
  return 0;
}