//https://leetcode.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        vector<vector<int>> matrix(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++)
        {
            if (colsum[i] == 2)
            {
                if (upper > 0 && lower > 0)
                {
                    matrix[0][i] = 1;
                    matrix[1][i] = 1;
                    upper--;
                    lower--;
                }
                else
                    return vector<vector<int>>(0);
            }
            else if (colsum[i] == 1)
            {
                if (upper >= lower && upper > 0)
                {
                    matrix[0][i] = 1;
                    upper--;
                }
                else if (upper < lower && lower > 0)
                {
                    matrix[1][i] = 1;
                    lower--;
                }
                else
                    return vector<vector<int>>(0);
            }
        }
        return upper == 0 && lower == 0 ? matrix : vector<vector<int>>(0);
    }
};