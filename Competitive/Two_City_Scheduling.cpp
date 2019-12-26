//https://leetcode.com/problems/two-city-scheduling/subm
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> A, vector<int> B)
{
    return (abs(A[0] - A[1])) > (abs(B[0] - B[1]));
}
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), compare);

        int A_cnt = 0, B_cnt = 0, res = 0;
        int size = (costs.size()) / 2;
        int i = 0;

        for (auto it : costs)
        {
            if (it[0] <= it[1])
            {                             //wanna pick A
                res += it[A_cnt >= size]; // if A_cnt reached size, pick it[1] which B
                if (A_cnt < size)
                    A_cnt++;
                else
                    B_cnt++;
            }
            else
            {
                res += it[B_cnt < size];
                if (B_cnt < size)
                    B_cnt++;
                else
                    A_cnt++;
            }
        }
        return res;
    }
};