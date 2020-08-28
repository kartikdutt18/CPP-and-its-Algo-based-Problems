#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void solve(string s)
{
  int minCuts = 0;
  bool isInc = true, isDec = true;
  for (int i = 1; i < s.length(); i++)
  {
    minCuts++;
    while (i < s.length() && s[i] >= s[i - 1])
      i++;
    while (i < s.length() && s[i] <= s[i - 1])
      i++;
  }

  cout << minCuts + 1 << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}