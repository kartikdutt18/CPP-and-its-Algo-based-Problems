//https://leetcode.com/problems/roman-to-integer/submissions/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution
{
public:
    int convert(char ch)
    {
        if (ch == 'I')
            return 1;
        if (ch == 'V')
            return 5;
        if (ch == 'X')
            return 10;
        if (ch == 'L')
            return 50;
        if (ch == 'C')
            return 100;
        if (ch == 'D')
            return 500;
        if (ch == 'M')
            return 1000;
        return 0;
    }
    int romanToInt(string s)
    {
        int ans = 0, i = 0;
        while (i < s.length())
        {
            if (i != s.length() - 1 && convert(s[i + 1]) > convert(s[i]))
            {
                ans += convert(s[i + 1]) - convert(s[i]);
                i += 2;
            }
            else
            {
                ans += convert(s[i]);
                i += 1;
            }
        }
        return ans;
    }
};
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}
