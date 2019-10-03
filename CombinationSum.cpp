//https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<int, vector<vector<int>>> ht;
    void Generate_Subsets(vector<int> num, vector<int> cur_set, int cur_sum, int i, int target)
    {
        //num: Vector containing all numbers
        //cur_set: Vector representing selected combination of numbers
        //cur_sum: Sum(cur_set)
        //i: Position from where to start
        if (i > num.size())
            return; //Return if iterator exceeds size of array
        if (cur_sum == target)
        {
            ht[cur_sum].push_back(cur_set); //Store Target Sum [Exceeds memory limit if you store all sums]
        }
        for (int j = i; j < num.size(); j++)
        { //Start from i and take one number and call recursilvely
            if (cur_sum + num[j] <= target)
            {                                                                //Call only if Current Sum < Target as all positive
                cur_set.emplace_back(num[j]);                                //Change Current Vector
                Generate_Subsets(num, cur_set, cur_sum + num[j], j, target); // Recursive Call
                //Put j=j+1 if one cannot reuse elements
                cur_set.pop_back();                                          //BackTrack
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        Generate_Subsets(candidates, {}, 0, 0, target);

        return ht[target];
    }
};