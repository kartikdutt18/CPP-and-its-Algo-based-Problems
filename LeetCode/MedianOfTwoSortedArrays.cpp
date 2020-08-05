#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    if (nums2.size() < nums1.size())
      return findMedianSortedArrays(nums2, nums1);

    int n = nums1.size(), m = nums2.size();
    int start = 0, end = n;
    while (start <= end)
    {
      int partition1 = (start + end) / 2;
      int partition2 = ((n + m + 1) / 2) - partition1;

      // See if partitions are sorted.
      int maxLeftX = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
      int minRightX = (partition1 == n) ? INT_MAX : nums1[partition1];

      int maxLeftY = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
      int minRightY = (partition2 == m) ? INT_MAX : nums2[partition2];

      if (maxLeftX <= minRightY && maxLeftY <= minRightX)
      {
        if ((n + m) % 2 == 0)
        {
          return 1.0 * ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        }
        else
          return max(maxLeftY, maxLeftX);
      }
      else if (maxLeftX > minRightY)
        end = partition1 - 1;
      else
        start = partition1 + 1;
    }

    return -1;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}