//https://leetcode.com/problems/robot-return-to-origin/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool judgeCircle(string moves)
{
    int x = 0;
    int y = 0;
    for (auto i : moves)
    {
        if (i == 'L')
            x--;
        if (i == 'R')
            x++;
        if (i == 'U')
            y++;
        if (i == 'D')
            y--;
    }

    return x == 0 && y == 0;
}