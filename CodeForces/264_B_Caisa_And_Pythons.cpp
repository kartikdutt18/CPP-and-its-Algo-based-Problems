#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n + 1);
  int curLevel = 0;
  int energyReqd = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> v[i + 1];
  }
  for(int i = 1; i <= n; i++)
  {
    curLevel = curLevel + (v[i - 1] - v[i]);
    if (curLevel < 0)
    {
      energyReqd += abs(curLevel);
      curLevel = 0;
    }
  }

  cout << energyReqd << endl;
  return 0;
}