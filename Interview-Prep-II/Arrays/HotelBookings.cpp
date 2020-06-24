#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
  int max_day = depart[max_element(depart.begin(), depart.end()) - depart.begin()];
  vector<int> dp(max_day + 1, 0);
  for (int i = 0; i < arrive.size(); i++)
  {
    dp[arrive[i]]++;
    dp[depart[i]]--;
  }
  int curRooms = 0;
  for (int i : dp)
  {
    curRooms += i;
    if (curRooms > K)
      return 0;
  }
  return 1;
}

bool Helper(vector<int> &arrive, vector<int> &depart, int K)
{
  vector<pair<int, int>> bookings;
  for (int i = 0; i < arrive.size(); i++)
  {
    if (arrive[i] != depart[i])
      bookings.push_back({arrive[i], depart[i]});
  }
  sort(bookings.begin(), bookings.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < bookings.size(); i++)
  {
    if (pq.empty() || pq.top() > bookings[i].first)
    {
      pq.push(bookings[i].second);
    }
    else
    {
      while (!pq.empty() && pq.top() <= bookings[i].first)
        pq.pop();
      pq.push(bookings[i].second);
    }
    if (pq.size() > K)
      return 0;
  }
  return pq.size() <= K;
}

int main()
{
  return 0;
}