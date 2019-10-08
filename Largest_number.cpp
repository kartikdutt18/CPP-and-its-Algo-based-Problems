//https://leetcode.com/problems/largest-number
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    string c = to_string(a);
    string d = to_string(b);
    return c + d > d + c;
}
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compare);
        string s = "";
        for (auto i : nums)
        {
            s += to_string(i);
        }
        while (s[0] == '0' && s.size() > 1)
            s = s.substr(1, s.length() - 1);
        return s;
    }
};