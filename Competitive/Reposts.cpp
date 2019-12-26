//https://codeforces.com/problemset/problem/522/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> ht;
    int ans = 0;
    ht["polycarp"] = 1;
    for (int i = 0; i <= n; i++)
    {
        string reposter, feed, temp;
        cin >> reposter >> temp >> feed;
        transform(reposter.begin(), reposter.end(), reposter.begin(), ::tolower);
        transform(feed.begin(), feed.end(), feed.begin(), ::tolower);
        ht[reposter] = ht[feed] + 1;
        ans = max(ht[reposter], ans);
    }
    cout << ans << endl;
    return 0;
}