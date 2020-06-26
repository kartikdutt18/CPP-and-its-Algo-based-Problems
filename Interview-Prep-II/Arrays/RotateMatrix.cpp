#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void rotate(vector<vector<int>> &A)
{
  if (A.size() == 0)
    return;
  for (int i = 0; i < A.size(); i++)
  {
    for (int j = 0; j < i; j++)
      swap(A[i][j], A[j][i]);
  }
  for (int i = 0; i < A.size(); i++)
    reverse(A[i].begin(), A[i].end());
}

int main() {
  return 0;
}