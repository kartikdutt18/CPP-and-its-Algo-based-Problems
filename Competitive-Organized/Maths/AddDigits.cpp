//https://leetcode.com/problems/add-digits/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while (to_string(num).length() != 1)
        {
            int temp = 0;
            while (num)
            {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};
int main()
{
    ll t;
    return 0;
}