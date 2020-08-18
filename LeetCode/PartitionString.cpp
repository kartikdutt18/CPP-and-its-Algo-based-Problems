#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> ht;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < S.length(); i++)
        {
            if (ht.count(S[i]))
                intervals[ht[S[i]]].second = i + 1;
            else
            {
                ht[S[i]] = intervals.size();
                intervals.push_back({ i + 1, i + 1 });
            }
        }

        vector<int> ans;
        int lastStart = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (ans.empty() || (ans.back() + lastStart) < intervals[i].first)
            {
                ans.push_back(intervals[i].second - intervals[i].first + 1);
                lastStart = intervals[i].first - 1;
            }
            else if (ans.back() < intervals[i].second - lastStart)
            {
                ans.back() = intervals[i].second - lastStart;
            }
        }


        return ans;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}