#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int s, vector<int> &nums)
  {
    int left = 0, minLength = INT_MAX, curSum = 0;
    for (int right = 0; right < nums.size(); right++)
    {
      curSum += nums[right];
      while ((curSum - nums[left]) >= s && left < right)
      {
        curSum -= nums[left];
        left++;
      }

      if (curSum >= s)
        minLength = min(right - left + 1, minLength);
    }

    return minLength == INT_MAX ? 0 : minLength;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}