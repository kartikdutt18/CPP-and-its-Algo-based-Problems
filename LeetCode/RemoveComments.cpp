#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  vector<string> removeComments(vector<string> &source)
  {
    bool longComments = false;
    bool singleComments = false;
    vector<string> code;
    string curString = "";
    for (string &line : source)
    {
      for (int i = 0; i < line.length(); i++)
      {
        // Search for end.
        if (i < line.length() && line[i] == '/' && line[i + 1] == '*' &&
            !singleComments && !longComments)
        {
          line[i + 1] = '$';
          longComments = true;
          continue;
        }

        else if (i > 0 && line[i - 1] == '*' && line[i] == '/' && longComments)
        {
          longComments = false;
          continue;
        }

        else if (i < line.length() - 1 && line[i] == '/' && line[i + 1] == '/' && !longComments)
        {
          singleComments = true;
          continue;
        }

        else if (!longComments && !singleComments)
        {
          curString += line[i];
        }
      }

      if (!curString.empty() && !longComments)
      {
        code.push_back(curString);
        curString = "";
      }

      singleComments = false;
    }

    return code;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}