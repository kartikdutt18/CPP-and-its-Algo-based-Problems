#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumGap(const vector<int> &A)
{
  if (A.size() == 1)
    return 0;
  vector<pair<int, int>> v;
  for (int i = 0; i < A.size(); i++)
    v.push_back(make_pair(A[i], i + 1));
  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
  });
  deque<int> maxIndices;
  maxIndices.push_back(-1);
  for (int i = v.size() - 1; i > 0; i--)
  {
    maxIndices.push_front(max(maxIndices.front(), v[i].second));
  }
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
  {
    ans = max(ans, maxIndices[i] - v[i].second);
  }
  return ans;
}

int main()
{
  return 0;
}