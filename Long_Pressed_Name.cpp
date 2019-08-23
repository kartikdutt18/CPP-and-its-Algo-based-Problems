//https://leetcode.com/problems/long-pressed-name/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isLongPressedName(string name, string typed)
{
    int i = 1;
    int j = 1;
    if (name[0] != typed[0])
        return false;
    while (i < name.length() && j < typed.length())
    {
        if (name[i] == typed[j])
        {
            i++;
            j++;
        }
        else if (name[i - 1] == typed[j])
        {
            j++;
        }
        else
        {
            return false;
        }
    }

    return i == name.length();
}
