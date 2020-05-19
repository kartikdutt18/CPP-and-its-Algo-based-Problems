#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(m ,0);
  for(int i = 0; i < m; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int i = 0, j = n - 1;
  int minDiff = INT_MAX;
  while(j < m)
  {
    minDiff = min(minDiff, v[j] - v[i]);
    j++;
    i++;
  }
  cout << minDiff << endl;
  return 0;
}