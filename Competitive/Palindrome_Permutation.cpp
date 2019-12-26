//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canPermutePalindrome(string s)
{
    int h[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        h[s[i]]++;
    }

    int oc = 0;

    for (int i = 0; i < 256; i++)
    {
        if (h[i] % 2 == 0)
            continue;
        else
            oc++;

        if (oc > 1)
            return false;
    }

    return true;
}