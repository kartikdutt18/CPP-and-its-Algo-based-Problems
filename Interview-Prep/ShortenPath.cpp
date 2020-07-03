#include <bits/stdc++.h>
using namespace std;

string shortenPath(string path)
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
      if (!simplerPath.empty() && simplerPath.back() != "..")
        simplerPath.pop_back();
      else if (path[0] != '/')
        simplerPath.push_back("..");
    }
    else if (token == "." || token.empty())
      continue;
    else
      simplerPath.push_back(token);
  }

  string ans = path[0] == '/' ? "/" : "";
  for (string token : simplerPath)
    ans = ans + token + "/";
  ans.length() > 1 ? ans.pop_back() : void();
  return ans;
}