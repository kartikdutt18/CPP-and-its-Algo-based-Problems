#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

tuple<long long, int, int> Kadane(vector<int> v)
{
  long long curSum = 0;
  long long maxSum = INT_MIN;
  int curStartIndex = 0;
  tuple<long long, int, int> posAns = {-1, -1, -1};
  for (int i = 0; i < v.size(); i++)
  {
    int num = v[i];
    curSum += num;
    if (maxSum < curSum)
    {
      maxSum = curSum;
      posAns = {maxSum, curStartIndex + 1, i + 1};
    }

    if (curSum < 0)
    {
      curSum = 0;
      curStartIndex = i + 1;
    }
  }
  return posAns;
}
vector<int> flip(string A)
{
  vector<int> v;
  for (char ch : A)
  {
    v.push_back(ch == '0' ? 1 : -1);
  }
  tuple<long long, int, int> ans = Kadane(v);
  if (get<0>(ans) < 0)
    return {};
  return {get<1>(ans), get<2>(ans)};
}

int main()
{
  return 0;
}