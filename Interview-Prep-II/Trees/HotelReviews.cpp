#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<int> solve(string A, vector<string> &B)
{
  unordered_set<string> goodWords;
  stringstream ss(A);
  while (ss.good())
  {
    string s;
    getline(ss, s, '_');
    goodWords.insert(s);
  }
  unordered_map<string, int> ht;
  for (string reviews : B)
  {
    stringstream sss(reviews);
    int count = 0;
    while (sss.good())
    {
      string s;
      getline(sss, s, '_');
      if (goodWords.count(s))
        count++;
    }
    ht[reviews] = count;
    // cout << reviews << " " << count << endl;
  }
  vector<pair<int, string>> v;
  for (int i = 0; i < B.size(); i++)
    v.push_back({i, B[i]});
  sort(v.begin(), v.end(), [&](pair<int, string> a, pair<int, string> b) {
    return ht[a.second] != ht[b.second] ? ht[a.second] > ht[b.second] : a.first < b.first;
  });
  vector<int> ans;
  for (int i = 0; i < v.size(); i++)
    ans.push_back(v[i].first);
  return ans;
}


int main()
{
  ios::sync_with_stdio(false);
  return 0;
}