#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> solve(int A)
{

  if (A == 0 || A == 1)
    return vector<vector<int>>(A, vector<int>(A, 1));

  vector<vector<int>> ans;
  ans.push_back({1});
  ans.push_back({1, 1});
  for (int i = 2; i < A; i++)
  {
    vector<int> v(i + 1, 1);
    for (int j = 1; j < v.size() - 1; j++)
    {
      v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
    }

    ans.push_back(v);
  }

  return ans;
}

int main()
{
  return 0;
}