#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int last_distinct = 1;
    int i = 1;
    int prev_distinct = nums[0];
    while (i != nums.size())
    {
        if (nums[i] == prev_distinct)
            i++;
        else
        {
            nums[last_distinct] = nums[i];
            prev_distinct = nums[i++];
            last_distinct++;
        }
    }
    return last_distinct;
}