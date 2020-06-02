#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int k;
  cin >> k;
  string s;
  while(s.length() == 0)
    getline(cin, s);
  if (s.length() % k != 0)
  {
    cout << -1 << endl;
    return 0;
  }

  unordered_map<char, int> ht;
  for (char ch : s)
    ht[ch]++;
  string ans = "";
  for (pair<char, int> pp : ht)
  {
    if (pp.second % k != 0)
    {
      cout << -1 << endl;
      return 0;
    }
    ans += string(pp.second / k, pp.first);
  }
  while(k--)
    cout << ans;
  return 0;
}