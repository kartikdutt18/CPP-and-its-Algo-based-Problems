#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> arr(n, 0);
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  vector<pair<ll, ll>> sums;
  ll curSum = 0;
  for (int i = 0; i < n; i++)
  {
    curSum += arr[i];
    if(i>k-1)
    {
      curSum -= arr[i - k];
      sums.push_back({curSum, sums.back().second + 1});
    }
    else if (i == k - 1)
    {
      sums.push_back({curSum, 1});
    }
  }
  vector<pair<ll, ll>> maxSums(sums.size(), {-1, -1});
  for(int i = sums.size() - 2; i >= 0; i--)
  {
    maxSums[i] = sums[i + 1].first >= maxSums[i + 1].first ? sums[i+1] : maxSums[i+1];
  }
  ll maxAns = -1, startIndex = -1, endIndex = -1;
  for (int i = 0; i < sums.size(); i++)
  {
    if ((i + k - 1 < sums.size()) && ((sums[i].first +
        maxSums[i+k - 1].first) > maxAns))
    {
      startIndex = sums[i].second;
      endIndex = maxSums[i + k - 1].second;
      maxAns = sums[i].first + maxSums[i + k - 1].first;
    }
  }
  cout << startIndex << " " << endIndex << endl;
  return 0;
}