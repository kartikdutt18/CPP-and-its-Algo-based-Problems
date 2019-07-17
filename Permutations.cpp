//https://leetcode.com/problems/permutations/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
void permute_1(vector<int> a, int l, int r)
{
    
    if (l == r)
        v.push_back(a);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute_1(a, l + 1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}
vector<vector<int>> permute(vector<int> nums)
{
    permute_1(nums, 0, nums.size() - 1);
    return v;
}