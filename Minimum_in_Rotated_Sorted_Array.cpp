//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int high = nums.size() - 1;
    int low = 0;
    int mid = (low + high) / 2;
    if (nums[high] > nums[0])
    {
        return nums[0];
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid - 1] > nums[mid])
            return nums[mid];
        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}