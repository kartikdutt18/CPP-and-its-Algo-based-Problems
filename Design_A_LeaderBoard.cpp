#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Leaderboard
{
    map<int, int> ht;
    map<int, set<int>> k_scores;

public:
    Leaderboard()
    {
    }

    void addScore(int playerId, int score)
    {
        if (ht.count(playerId))
        {
            int prev_score = ht[playerId];
            ht[playerId] += score;
            k_scores[prev_score].erase(playerId);
            k_scores[ht[playerId]].insert(playerId);
        }
        else
        {
            ht[playerId] += score;
            k_scores[ht[playerId]].insert(playerId);
        }

        return;
    }

    int top(int K)
    {
        int cnt = 0;
        int score = 0;
        for (auto i = k_scores.rbegin(); cnt < K, i != k_scores.rend(); i++)
        {
            for (auto playerId : i->second)
            {
                if (cnt <= K - 1)
                {
                    score += ht[playerId];
                    cnt++;
                }
                else
                    break;
            }
        }
        return score;
    }

    void reset(int playerId)
    {
        if (ht.count(playerId))
        {
            int prev_score = ht[playerId];
            ht[playerId] = 0;
            k_scores[prev_score].erase(playerId);
            k_scores[ht[playerId]].insert(playerId);
        }
        return;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */