//https://leetcode.com/problems/move-zeroes/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    for (int cur_ind = 0, last_ind = 0; cur_ind < nums.size(); cur_ind++)
    {
        if (nums[cur_ind] != 0)
        {
            swap(nums[cur_ind], nums[last_ind++]);
        }
    }
    return;
}