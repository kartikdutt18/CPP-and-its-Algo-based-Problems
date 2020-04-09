// https://leetcode.com/contest/weekly-contest-175/problems/tweet-counts-per-frequency/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class TweetCounts
{

  map<int, set<string>> tweets;

public:
  TweetCounts()
  {
  }

  void recordTweet(string tweetName, int time)
  {
    tweets[time].insert(tweetName);
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
  {
    int multiplier = 3600 * 60;
    if (freq == "minute")
      multiplier = 60;
    if (freq == "hour")
      multiplier = 3600;
    if (freq == "day")
      multiplier = 3600 * 60;
    vector<int> ans;

    int cur_ans = 0;
    for (int i = startTime; i <= endTime; i++)
    {
      if (i >= (startTime + multiplier))
      {
        ans.push_back(cur_ans);
        startTime += multiplier;
        cur_ans = 0;
      }
      if (tweets.count(i))
      {
        cur_ans += tweets[i].count(tweetName);
      }
    }
    ans.push_back(cur_ans);
    return ans;
  }
};
int main() {

return 0;
}