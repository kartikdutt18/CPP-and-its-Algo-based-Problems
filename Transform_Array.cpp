//https://leetcode.com/contest/biweekly-contest-12/problems/array-transformation/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> transformArray(vector<int> &arr)
    {
        if (arr.size() == 0)
            return arr;
        vector<int> prev_arr = arr;
        do
        {
            prev_arr = arr;
            vector<int> temp = arr;
            for (int i = 1; i < arr.size() - 1; i++)
            {
                if (temp[i - 1] < temp[i] && temp[i + 1] < temp[i])
                    arr[i] -= 1;
                else if (temp[i - 1] > temp[i] && temp[i + 1] > temp[i])
                    arr[i] += 1;
            }
        } while (prev_arr != arr);
        return arr;
    }
};