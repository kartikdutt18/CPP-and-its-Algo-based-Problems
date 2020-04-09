//https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Generate_Subsets(int i, vector<int> arr, vector<vector<int>> &ans, vector<int> &cur_sum)
    {
        ans.push_back(cur_sum);
        for (int j = i; j < arr.size(); j++)
        {
            cur_sum.push_back(arr[j]);
            Generate_Subsets(j + 1, arr, ans, cur_sum);
            cur_sum.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> subsets;
        vector<int> cur_sum = {};
        Generate_Subsets(0, candidates, subsets, cur_sum);
        set<vector<int>> ans;
        for (auto i : subsets)
        {

            if (accumulate(i.begin(), i.end(), 0) == target)
            {
                sort(i.begin(), i.end());
                ans.insert(i);
            }
        }
        vector<vector<int>> fin;
        for (auto i : ans)
        {
            fin.push_back(i);
        }
        return fin;
    }
};

//DFS SOLUTION::::

void dfs(vector<int> candidates, vector<int> &Set, vector<vector<int>> &Result, int target, int depth)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        Result.push_back(Set);
        return;
    }
    else
    {
        int i;
        for (i = depth; i < candidates.size(); ++i)
        {
            if (candidates[i] <= target)
            {
                Set.push_back(candidates[i]);
                dfs(candidates, Set, Result, target - candidates[i], i + 1);
                while (Set.back() == candidates[i + 1])
                    ++i;
                Set.pop_back();
            }
            else
                break;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> Result;
    vector<int> Set;
    std::sort(candidates.begin(), candidates.end());
    candidates.push_back(INT_MAX); //add a sentinel to prevent heap buffer overflow.
    dfs(candidates, Set, Result, target, 0);
    return Result;
}