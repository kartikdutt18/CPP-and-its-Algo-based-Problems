#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int cnt = 0;
  string s = "";
  while(s.length() == 0)
    getline(cin, s);
  for (char num : s)
    cnt += (num == '4' || num == '7');
  queue<string> q;
  q.push("4");
  q.push("7");
  while(!q.empty())
  {
    string cur = q.front();
    q.pop();
    if (cur == to_string(cnt))
    {
      cout << "YES\n";
      return 0;
    }

    if ((cur + "4").length() <= to_string(cnt).length())
      q.push(cur + "4");
    if ((cur + "7").length() < (to_string(cnt)).length())
      q.push("7");
  }
  cout << "NO\n";
  return 0;
}