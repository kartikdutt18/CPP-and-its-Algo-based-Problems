//https://leetcode.com/problems/combinations/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void generate(int n,int k,int i,vector<int> temp){
    if(temp.size()>=k) {
        ans.push_back(temp);
        return ;
    }
    if (i > n)
        return;
    if(temp.size()>k) return;
    temp.push_back(i);
    generate(n,k+1,i,temp);
    temp.pop_back();
    generate(n, k + 1, i, temp);
}
vector<vector<int>> combine(int n, int k)
{
    generate(n,k,0,{});
    return ans;
}

class Solution{
    bool allPossibleCombinations(vector<vector<int>> &ans, vector<int> comb, long int be, long int n, long int k)
    {
        if (comb.size() == k)
        {
            ans.push_back(comb);
            return false;
        }

        if (be > n)
            return false;

        for (long int i = be; i <= n; i++)
        {
            if (comb.size() && i <= comb.back())
                continue;
            comb.push_back(i);
            if (allPossibleCombinations(ans, comb, be + 1, n, k))
                return true;
            comb.pop_back();
        }
        return false;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        allPossibleCombinations(ans, comb, 1, n, k);
        return ans;
    }
};