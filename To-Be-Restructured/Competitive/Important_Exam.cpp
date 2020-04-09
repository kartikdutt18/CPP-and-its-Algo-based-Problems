//https://codeforces.com/contest/1201/problem/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int temp = n;
    vector<string> ans;
    while (temp--)
    {
        string s = "";
        while (s.length() == 0)
        {
            getline(cin, s);
        }
        ans.push_back(s);
    }
    vector<int> scores;
    temp = m;
    while (temp--)
    {
        int t;
        cin >> t;
        scores.push_back(t);
    }
    int max_score = 0;
    for (int i = 0; i < m; i++)
    {
        map<char, int> ht;
        int max_freq = 1;
        for (int j = 0; j < n; j++)
        {
            ht[ans[j][i]] += 1;
            max_freq = max(max_freq, ht[ans[j][i]]);
        }
        max_score += scores[i] * max_freq;
    }
    cout << max_score << endl;
    return 0;
}