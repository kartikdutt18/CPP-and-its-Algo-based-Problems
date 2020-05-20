#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll curSum = 0;
  ll minIndex = 1;
  ll minSum = INT_MAX;
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  deque<int> dq;
  for (int i = 0; i < n; i++)
  {
    dq.push_back(v[i]);
    curSum += v[i];
    if (dq.size() > k)
    {
      curSum -= dq.front();
      dq.pop_front();
    }
    if (dq.size() == k && curSum < minSum)
    {
      minSum = curSum;
      minIndex = i - k + 1;
    }
  }
  cout << minIndex + 1 << endl;
  return 0;
}