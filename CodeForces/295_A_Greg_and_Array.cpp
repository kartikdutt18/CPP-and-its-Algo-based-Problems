#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void BuildTree(vector<ll>& segmentTree, const vector<ll>& arr,
    size_t start, size_t end, size_t index)
{
  if (start > end)
    return;
  if (start == end)
  {
    segmentTree[index] = arr[start];
    return;
  }

  size_t mid = (start + end) / 2;
  BuildTree(segmentTree, arr, start, mid, 2 * index + 1);
  BuildTree(segmentTree, arr, mid + 1, end, 2 * index + 2);
  segmentTree[index] = segmentTree[2 * index + 1] +
      segmentTree[2 * index + 2];
  return;
}

void UpdateTreeLazy(vector<ll>& lazy, vector<ll>& segmentTree,
    ll delta, size_t startRange, size_t endRange, size_t index,
    size_t startIndex, size_t endIndex)
{
  if (startIndex > endIndex)
  {
    return;
  }

  // Number of elements in a segment = endIndex - startIndex + 1.
  // Propogate lazy sum.
  if (lazy[index] != 0)
  {
    segmentTree[index] += (endIndex - startIndex + 1) * delta;
    if (startIndex != endIndex)
    {
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    lazy[index] = 0;
  }

  // No overlap.
  if (startIndex >= endRange || endIndex <= startRange)
  {
    return;
  }

  // Complete overlap.
  if (startIndex >= startRange && endIndex <= endRange)
  {
    segmentTree[index] = (endIndex - startIndex + 1) * delta;
    if (startIndex != endIndex)
    {
      lazy[2 * index + 1] += delta;
      lazy[2 * index + 2] += delta;
    }
    return;
  }

  // Partial Overlap.
  size_t mid = (startIndex + endIndex) / 2;
  UpdateTreeLazy(lazy, segmentTree, delta, startRange, endRange,
      2 * index + 1, startIndex, mid);
  UpdateTreeLazy(lazy, segmentTree, delta, startRange, endRange,
      2 * index + 2, mid + 1, endIndex);
  segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
  return;
}

// Query isn't required, writing for practice.
ll Query(vector<ll> lazy, vector<ll> segmentTree, size_t startRange,
    size_t endRange, size_t index, size_t startIndex, size_t endIndex)
{
  if (startIndex > endIndex)
  {
    return 0;
  }

  if (lazy[index] != 0)
  {
    segmentTree[index] += (endIndex - startIndex + 1) * lazy[index];
    if (startIndex != endIndex)
    {
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    lazy[index] = 0;
  }

  // No overlap.
  if (startIndex >= endRange || endIndex <= startRange)
  {
    return 0;
  }

  // Complete overlap.
  if (startIndex >= startRange && endIndex <= endRange)
  {
    return segmentTree[startRange];
  }

  size_t mid = (startIndex + endIndex) / 2;
  return Query(lazy, segmentTree, startRange, endRange,
      2 * index + 1, startIndex, mid) + Query(lazy, segmentTree,
      startRange, endRange, 2 * index + 2, mid + 1, endIndex);
}

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<ll> segmentTree(4 * n + 1, 0);
  vector<ll> lazyTree(4 * n + 1, 0);

  for (size_t i = 0; i < m; i++)
  {
    ll delta;
    size_t startRange, endRange;
    cin >> startRange >> endRange >> delta;
    UpdateTreeLazy(lazyTree, segmentTree, delta, startRange,
        endRange, 0, 0, n - 1);
  }

  for (size_t i = 0; i < k; i++)
  {
    size_t startRange, endRange;
    cin >> startRange >> endRange;
    UpdateTreeLazy(lazyTree, segmentTree, 1, startRange,
        endRange, 0, 0, n - 1);
  }

  for (size_t i = 0; i < n; i++)
  {
    cout << Query(lazyTree, segmentTree, i, i, 0, 0, n - 1) << " ";
  }
  cout << endl;
}

int main()
{
  solve();
  return 0;
}