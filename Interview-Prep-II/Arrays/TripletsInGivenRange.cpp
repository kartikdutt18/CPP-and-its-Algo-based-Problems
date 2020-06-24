#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int  solve(vector<string> &A)
{
  vector<double> v;
  for (string num : A)
    v.push_back(stod(num));
  sort(v.begin(), v.end());
  int j = v.size() - 1;
  int i = 0;
  int k = i + 1;
  bool lastMoved = 1;
  while (k < j && i < k)
  {
    // cout << v[i] << " " << v[j] << " " << v[k] << endl;
    double sum = v[i] + v[j] + v[k];
    if (sum > 1 && sum < 2)
      return 1;
    if (sum < 1)
    {
      if (lastMoved)
        k++;
      else
        i++;
      lastMoved = !lastMoved;
    }
    else
      j--;
  }
  return 0;
}

int main()
{
  return 0;
}