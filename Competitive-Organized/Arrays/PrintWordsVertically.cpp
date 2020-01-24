//https://leetcode.com/contest/weekly-contest-172/problems/print-words-vertically/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<char>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    vector<string> printVertically(string s)
    {
        vector<string> dq;
        stringstream ss(s);
        while (ss.good())
        {
            string temp;
            ss >> temp;
            dq.push_back(temp);
        }
        vector<vector<char>> matrix(200, vector<char>(200, ' '));
        for (int i = 0; i < dq.size(); i++)
        {
            for (int j = 0; j < dq[i].length(); j++)
                matrix[i][j] = dq[i][j];
        }
        rotate(matrix);
        vector<string> ans;
        for (int i = 0; i < matrix.size(); i++)
        {
            string temp = "";
            for (int j = 0; j < matrix[i].size(); j++)
                temp += matrix[i][j];
            while (temp.length() > 0 && temp.back() == ' ')
                temp.pop_back();
            cout << temp << endl;
            if (temp.length())
                ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    ll t;
    return 0;
}