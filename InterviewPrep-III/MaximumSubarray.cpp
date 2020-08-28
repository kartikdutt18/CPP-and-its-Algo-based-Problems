#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void solve(vector<int> v, int k)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == k)
    {
      v[i] = 0;
    }
    else if (v[i] > k)
      v[i] = 1;
    else
      v[i] = -1;
  }

  int totalSum = accumulate(v.begin(), v.end(), 0);
  unordered_map<int, int> ht;
  int minLen = v.size();
  ht.insert({0, 0});
  int curSum = 0;
  int target = totalSum;
  for (int i = 0; i < v.size(); i++)
  {
    curSum += v[i];
    if (ht.count(-target + curSum))
    {
      minLen = min(minLen, i - ht[target - curSum]);
    }

    ht[curSum] = i;
  }
  cout << v.size() - minLen << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    solve(v, k);
  }
  return 0;
}