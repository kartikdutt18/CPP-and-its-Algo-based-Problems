#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int> v)
{
  int n = v.size();
  deque<int> ans;
  ll maxVal = INT_MIN;
  int lastIndex = v.size();
  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] >= maxVal)
    {
      maxVal = v[i];
      ans.push_front(v[i]);
    }
  }

  for(int i : ans)
    cout << i << " ";
  return 1;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    solve(v);
  }
  return 0;
}