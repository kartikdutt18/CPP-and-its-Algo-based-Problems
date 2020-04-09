//https://leetcode.com/contest/biweekly-contest-19/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    if (arr.size() < k)
      return 0;
    deque<int> dq;
    double cur_avg = 0;
    for (int i = 0; i < k; i++)
    {
      dq.push_back(arr[i]);
      cur_avg += (double)arr[i] / k;
    }
    int ans = (cur_avg >= threshold);
    for (int i = k; i < arr.size(); i++)
    {
      cur_avg -= (double)dq.front() / k;
      cur_avg += (double)arr[i] / k;
      ans += (cur_avg >= threshold);
      dq.push_back(arr[i]);
      dq.pop_front();
    }
    return ans;
  }
};
int main() {

  return 0;
}