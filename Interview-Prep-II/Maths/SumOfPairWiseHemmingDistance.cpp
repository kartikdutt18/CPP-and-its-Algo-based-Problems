#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int hammingDistance(const vector<int> &nums)
{
  long long ans = 0;
  for (int i = 0; i < 32; i++)
  {
    long long ones = 0, zeros = 0;
    for (int j = 0; j < nums.size(); j++)
    {
      if (nums[j] < 0)
        continue;
      int bit = (nums[j] >> i) & 1;
      if (bit)
        ones++;
      else
        zeros++;
    }
    ans += (ones * zeros) % 1000000007;
  }
  return (2 * ans) % 1000000007;
}

int main()
{
  return 0;
}