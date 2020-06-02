#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    v[t] = i + 1;
  }
  for (int i = 1; i <=n; i++)
    cout << v[i] << " ";
  return 0;
}