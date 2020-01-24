//https://leetcode.com/contest/weekly-contest-172/problems/maximum-69-number/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string n = to_string(num);
        int i = 0;
        while (i < n.length())
        {
            if (n[i] == '6')
            {
                n[i] = '9';
                break;
            }
            i++;
        }
        stringstream ss(n);
        int ans;
        ss >> ans;
        return ans;
    }
};
int main()
{
    return 0;
}