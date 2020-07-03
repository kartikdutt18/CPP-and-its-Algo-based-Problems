#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    stringstream tokenizer(path);
    vector<string> tokens;
    string curPath;
    while (getline(tokenizer, curPath, '/'))
      tokens.push_back(curPath);

    deque<string> simplerPath;
    for (string token : tokens)
    {
      if (token == "..")
      {
        if (!simplerPath.empty())
          simplerPath.pop_back();
      }
      else if (token == "." || token.empty())
        continue;
      else
      {
        simplerPath.push_back(token);
      }
    }
    string ans = "/";
    for (string token : simplerPath)
      ans = ans + token + "/";
    ans.length() > 1 ? ans.pop_back() : void();
    return ans;
  }
};

int main()
{
  return 0;
}