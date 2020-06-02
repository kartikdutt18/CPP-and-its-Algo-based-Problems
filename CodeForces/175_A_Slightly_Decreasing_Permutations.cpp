#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i]= i + 1;
  reverse(v.begin() + n - k - 1, v.end());
  for(auto i : v)
    cout << i << " ";
  return 0;
}