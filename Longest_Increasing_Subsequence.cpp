//https://leetcode.com/problems/longest-increasing-subsequence/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> parent(nums.size() + 2, -1);
    vector<int> longest_sub_seq(nums.size() + 2, 0);
    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int low = 1;
        int high = len;
        while (low <= high)
        {
            int mid = (low + high) % 2 ? (low + high) / 2 + 1 : (low + high) / 2;
            if (nums[longest_sub_seq[mid]] < nums[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        int pos = low;
        parent[i] = longest_sub_seq[pos - 1];
        longest_sub_seq[pos] = i;
        if (pos > len)
        {
            len = pos;
        }
    }
    int k = longest_sub_seq[len];
    //Print will be in Reverse
    for (int i = len - 1; i > 0; i--)
    {
        cout << nums[k] << " ";
        k = parent[k];
    }
    return len;
}