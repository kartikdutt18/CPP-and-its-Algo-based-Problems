//https://leetcode.com/problems/find-the-duplicate-number/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return -1;

    int slow = nums[0];
    int fast = nums[0];
    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);
    fast = nums[0];

    while (fast != slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}