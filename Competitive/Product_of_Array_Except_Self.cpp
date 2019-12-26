//https://leetcode.com/problems/product-of-array-except-self/solution/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> output(nums.size());
    output[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        output[i] = output[i - 1] * nums[i - 1];
    }
    int cur_prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        output[i] = output[i] * cur_prod;
        cur_prod *= nums[i];
    }
    return output;

}