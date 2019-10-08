#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = rand() % (high - low + 1) + low;
        if (nums[mid] == target)
            return true;
        if (nums[high] == target || nums[low] == target)
            return true;
        if (nums[low] < nums[mid])
        {
            if (target > nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (nums[high] > nums[mid])
            if (target > nums[mid] && target < nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        else
            high--;
    }
    return false;
}