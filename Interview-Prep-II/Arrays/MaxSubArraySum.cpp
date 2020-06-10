#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
  int maxSubArraySum(vector<int> A)
  {
    int curSum = 0;
    int maxSum = INT_MIN;
    for (int num : A)
    {
      curSum += num;
      maxSum = max(curSum, maxSum);
      if (curSum < 0)
        curSum = 0;
    }
    return maxSum;
  }
};

int main()
{

  return 0;
}