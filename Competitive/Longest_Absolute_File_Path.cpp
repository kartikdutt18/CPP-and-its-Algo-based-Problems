//https://leetcode.com/contest/warm-up-contest/problems/longest-absolute-file-path/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Tree
{
    vector<int> levels;

public:
    int buildTree(string s)
    {
        int level = 0, ans = 0, file = 0, dirLen = 0, curLen = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == '\n' || i == s.length())
            {
                if (file)
                    ans = max(dirLen + curLen, ans);
                else
                {
                    levels.resize(level);
                    levels.push_back(curLen);
                }
                level = 0;
                file = 0;
                curLen = 0;
                dirLen = 0;
            }
            else if (s[i] == '\t')
            {
                dirLen += levels[level] + 1;
                level++;
            }
            else
            {

                curLen++;
                if (s[i] == '.')
                    file = 1;
            }
        }
        return ans;
    }
};
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        Tree t;
        return t.buildTree(input);
        //t.printTree();
        //return 0;
    }
};