#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseParentheses(string s)
    {
        string ans = "";
        stack<string> v;
        v.emplace("");
        for (auto i : s)
        {
            if (i == '(' || v.empty())
            {
                v.emplace("");
            }
            else if (i == ')')
            {
                string t = v.top();
                reverse(t.begin(), t.end());
                v.pop();
                string temp = v.top();
                v.pop();
                v.emplace(temp + t);
            }
            else
            {
                string temp = v.top();
                v.pop();
                temp += i;
                v.emplace(temp);
            }
        }
        return v.top();
    }
};