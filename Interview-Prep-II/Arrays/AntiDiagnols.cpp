#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isValid(int x, int y, int n, int m)
{
  return x >= 0 && y >= 0 && x < n && y < m;
}
vector<vector<int>> diagonal(vector<vector<int>> &A)
{
  vector<vector<int>> ans;
  for (int i = 0; i < A[0].size(); i++)
  {
    vector<int> temp;
    int j = 0;
    int k = i;
    while (isValid(j, k, A.size(), A[0].size()))
    {
      temp.push_back(A[j++][k--]);
    }
    ans.push_back(temp);
  }
  for (int i = 1; i < A.size(); i++)
  {
    int j = i;
    int k = A[0].size() - 1;
    vector<int> temp;
    while (isValid(j, k, A.size(), A[0].size()))
    {
      temp.push_back(A[j++][k--]);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main()
{
  return 0;
}