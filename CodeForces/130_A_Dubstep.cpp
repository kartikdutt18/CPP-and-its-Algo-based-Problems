#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s;
  while(s.length() == 0)
  {
    getline(cin, s);
  }
  string ans = "";
  string temp = "";
  bool flag = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if (i + 2 < s.length() && s.substr(i, 3) == "WUB")
    {
      flag = true;
      i+=2;
      ans += temp;
      temp = "";
      continue;
    }
    else
    {
      if (flag && !ans.empty())
      {
        temp += " ";
        flag = false;
      }

      temp += s[i];
    }
  }
  if (!temp.empty())
    ans += temp;
  cout << ans << endl;
  return 0;
}