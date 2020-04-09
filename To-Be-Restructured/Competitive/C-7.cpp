#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//https : //leetcode.com/contest/biweekly-contest-7/problems/single-row-keyboard/
        class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        map<char, int> ht;
        for (int i = 0; i < keyboard.length(); i++)
        {
            ht[keyboard[i]] = i;
        }
        int prev = 0;
        int dist = 0;
        for (auto i : word)
        {
            dist += abs(ht[i] - prev);
            prev = ht[i];
        }
        return dist;
    }
};

//https : //leetcode.com/contest/biweekly-contest-7/problems/minimum-cost-to-connect-sticks/

class Solution
{
public:
    int connectSticks(vector<int> &sticks)
    {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int sum = 0;
        while (pq.size() > 1)
        {
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            int t_sum = t1 + t2;
            pq.push(t_sum);
            sum += t_sum;
        }

        return sum;
    }
};