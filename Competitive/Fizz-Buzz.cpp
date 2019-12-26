//https://leetcode.com/problems/fizz-buzz/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> v;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        if (i % 3 == 0)
            s = "Fizz";
        if (i % 5 == 0)
            s = "Buzz";
        if (i % 3 == 0 && i % 5 == 0)
            s = "FizzBuzz";
        v.push_back(s);
    }
    return v;
}