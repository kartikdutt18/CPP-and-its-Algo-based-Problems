//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> pad = {
    "", "", "abc", "def", 
    "ghi", "jkl", "mno", 
    "pqrs", "tuv", "wxyz"
    };

vector<string> ans;

void Generate_Combinations(string digits, string cur_set, int i)
{
    if (i >= digits.length())
    {
        ans.push_back(cur_set);
        return;
    }

    for (int j = 0; j < pad[digits[i] - '0'].length(); j++)
    {
        cur_set.push_back(pad[digits[i] - '0'][j]);
        Generate_Combinations(digits, cur_set, i + 1);
        cur_set.pop_back();
    }
    return;
}
vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
        return {};
    Generate_Combinations(digits, "", 0);
    return ans;
}