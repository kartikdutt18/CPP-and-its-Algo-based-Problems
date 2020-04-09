//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] > 0)
            max_profit += prices[i] - prices[i - 1];
    }
    return max_profit;
}