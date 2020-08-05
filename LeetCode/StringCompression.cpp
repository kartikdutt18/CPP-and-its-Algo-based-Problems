#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int lenPtr = 0;
    int i = 0;
    while (i < chars.size())
    {
      int j = i + 1;
      int cnt = 1;
      while (j < chars.size() && chars[j] == chars[i])
      {
        j++;
        cnt++;
      }

      chars[lenPtr++] = chars[i];
      if (cnt != 1)
      {
        string num = to_string(cnt);
        for (int k = 0; k < num.length(); k++)
        {
          chars[lenPtr++] = num[k];
        }
      }

      i = j;
    }

    return lenPtr;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}