//https://leetcode.com/problems/merge-sorted-array/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = nums1.size() - 1;
    while (i >= 0 && j >= 0 && k >= 0)
    {
        if (nums2[j] >= nums1[i])
            nums1[k--] = nums2[j--];
        else
            nums1[k--] = nums1[i--];
    }

    while (j >= 0 && k >= 0)
    {
        nums1[k--] = nums2[j--];
    }
    return;
}