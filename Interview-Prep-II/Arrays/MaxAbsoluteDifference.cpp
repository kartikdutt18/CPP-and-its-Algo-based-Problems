#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxArr(vector<int> &A)
{
  int maxNum = INT_MIN;
  int maxNum2 = INT_MIN;
  int minNum = INT_MAX;
  int minNum2 = INT_MAX;
  for (int i = 0; i < A.size(); i++)
  {
    maxNum = max(maxNum, A[i] + i);
    maxNum2 = max(maxNum2, A[i] - i);
    minNum = min(minNum, A[i] + i);
    minNum2 = min(minNum2, A[i] - i);
  }
  return max(maxNum - minNum, maxNum2 - minNum2);
}

int main()
{
  return 0;
}